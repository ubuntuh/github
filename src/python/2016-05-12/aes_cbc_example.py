#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import base64
from Crypto import Random
from Crypto.Cipher import AES

# AES 暗号における key size は 16、24、32 バイトのいずれかであるがここでは 32 バイトを用いる。また、AES 暗号における block size は 16 バイトであって、本文のサイズは 16 バイトの倍数であればよいが、ここでは処理の単純化のためにより厳しく 32 バイトの倍数とする。
block_size = 32
def pad(byte):
    num_pad = block_size - len(byte) % block_size
    padded = byte + bytes([num_pad] * num_pad)
    return padded
def unpad(byte):
    last_character = byte[len(byte) - 1:]
    num_pad = ord(last_character)
    unpadded = byte[:-num_pad]
    return unpadded
def encrypt(plain_text, password):
    byte = plain_text.encode('utf-8')
    padded = pad(byte)
    password_byte = password.encode('utf-8')
    padded_password = pad(password_byte)
    initialization_vector = Random.new().read(AES.block_size)
    cipher = AES.new(padded_password, AES.MODE_CBC, initialization_vector)
    encrypted = cipher.encrypt(padded)
    encoded = base64.b64encode(initialization_vector + encrypted)
    return encoded
def decrypt(encrypted_text, password):
    decoded = base64.b64decode(encrypted_text)
    password_byte = password.encode('utf-8')
    padded_password = pad(password_byte)
    initialization_vector = decoded[:AES.block_size]
    cipher = AES.new(padded_password, AES.MODE_CBC, initialization_vector)
    encrypted = decoded[AES.block_size:]
    decrypted = cipher.decrypt(encrypted)
    unpadded = unpad(decrypted)
    plain_text = unpadded.decode('utf-8')
    return plain_text

password = 'password'
plain_text = 'hello, world'
encrypted = encrypt(plain_text, password)
print('Encrypted =', encrypted)
decrypted = decrypt(encrypted, password)
print('Decrypted =', decrypted)
