#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import base64
import hashlib
import os
from Crypto.Cipher import AES

block_size = AES.block_size # = 16
len_salt = block_size
hash_name = 'sha256' # ハッシュアルゴリズムは秘密ではない。
iterations = 100000 # この回数は秘密ではない。
def getKey(hash_name, salt, iterations, password):
    """パスワードから鍵を得る。パスワードと鍵は共に秘密である。key derivation function として PKCS5 に定められる PBKDF2 を使う。"""
    password_byte = password.encode('utf-8')
    key = hashlib.pbkdf2_hmac(hash_name, password_byte, salt, iterations, 32)
    return key
def pad(byte):
    """中途半端な長さのバイト列を十分な長さにする。"""
    num_pad = block_size - len(byte) % block_size
    padded = byte + bytes([num_pad] * num_pad)
    return padded
def unpad(byte):
    """パディングを除去する。パディング部分の判定には PKCS7 padding を用いる。"""
    last_character = byte[len(byte) - 1:]
    num_pad = ord(last_character)
    unpadded = byte[:-num_pad]
    return unpadded
def encrypt(plain_text, password):
    salt = os.urandom(len_salt) # salt を作成する。salt は秘密ではない。
    initialization_vector = os.urandom(block_size) # IV とも言う。IV は秘密ではない。
    key = getKey(hash_name, salt, iterations, password)
    byte = plain_text.encode('utf-8')
    padded = pad(byte)
    cipher = AES.new(key, AES.MODE_CBC, initialization_vector) # 暗号化モード CBC は Cipher-Block Chaining の意味である。暗号化モードは秘密ではない。
    encrypted = cipher.encrypt(padded)
    joined = b', '.join([hash_name.encode('utf-8'), salt, str(iterations).encode('utf-8'), initialization_vector, encrypted])
    encoded = base64.b64encode(joined)
    return encoded
def decrypt(encrypted_text, password):
    decoded = base64.b64decode(encrypted_text)
    hash_name, salt, iterations_byte, initialization_vector, encrypted = decoded.split(b', ', 4)
    key = getKey(hash_name.decode('utf-8'), salt, int(iterations_byte), password)
    cipher = AES.new(key, AES.MODE_CBC, initialization_vector)
    decrypted = cipher.decrypt(encrypted)
    unpadded = unpad(decrypted)
    plain_text = unpadded.decode('utf-8')
    return plain_text

if __name__ == '__main__':
    password = 'password'
    plain_text = 'hello, world'
    encrypted = encrypt(plain_text, password)
    print('Encrypted =', encrypted)
    decrypted = decrypt(encrypted, password)
    print('Decrypted =', decrypted)
