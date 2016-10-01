#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from Crypto.Cipher import AES

# key の長さは 16 bytes or 24 bytes or 32 bytes。
# message の長さは 16 bytes の倍数。
key = b'0123456789012345'
cipher = AES.new(key, AES.MODE_ECB) # ここでは ECB モードを使っているが、ECB モードを使うと秘密性が得られないので実際には使えない。
message = 'hello, world!!!!'
encrypted = cipher.encrypt(message)
print('Encrypted =', encrypted)
decrypted = cipher.decrypt(encrypted) # ここでは AESCipher オブジェクトを使いまわしているが、正しい行為か不明。すでに別の方法を検討しているので立ち入らない。
print('Decrypted =', decrypted)
