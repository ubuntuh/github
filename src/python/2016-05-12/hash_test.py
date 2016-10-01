#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import hashlib

string = 'string'
byte = string.encode('utf-8')
sha256 = hashlib.sha256(byte)
hex_string = sha256.hexdigest()
print('SHA-256 =', hex_string)

from Crypto.Hash import SHA256

hash = SHA256.new()
hash.update(byte)
sha256 = hash.hexdigest()
print('SHA-256 =', sha256)
