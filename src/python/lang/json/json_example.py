#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import collections
import json

class JSONSerializable:
    def json_decode(dictionary):
        return JSONSerializable()
    def json_encode(self):
        dictionary = collections.OrderedDict()
        dictionary['class'] = type(self).__name__
        return dictionary

class MyObject(JSONSerializable):
    def json_decode(dictionary):
        print('Decoding "MyObject".')
        value_0 = dictionary['value_0']
        value_1 = dictionary['value_1']
        value_2 = dictionary['value_2'] # Already decoded from JSON.
        obj = MyObject(value_0, value_1, value_2)
        return obj
    def __init__(self, value_0, value_1, value_2):
        self.value_0 = value_0
        self.value_1 = value_1
        self.value_2 = value_2
    def json_encode(self):
        print('Encoding "MyObject".')
        dictionary = super().json_encode()
        dictionary['value_0'] = self.value_0
        dictionary['value_1'] = self.value_1
        dictionary['value_2'] = self.value_2.json_encode()
        return dictionary

class Nested(JSONSerializable):
    def json_decode(dictionary):
        print('Decoding "Nested".')
        return Nested(dictionary['value'] ** (1 / 8))
    def __init__(self, value):
        self.value = value
    def json_encode(self):
        print('Encoding "Nested".')
        dictionary = super().json_encode()
        dictionary['value'] = self.value ** 8
        return dictionary

class Encoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, MyObject):
            return obj.json_encode()
        return super().default(self, obj)

class Decoder(json.JSONDecoder):
    def __init__(self):
        super().__init__(object_hook=self._hook)
    def _hook(self, dictionary):
        if not 'class' in dictionary:
            return dictionary
        if dictionary['class'] == 'MyObject':
            return MyObject.json_decode(dictionary)
        if dictionary['class'] == 'Nested':
            return Nested.json_decode(dictionary)
        return dictionary

object_0 = MyObject(111, 222, Nested(2))
dictionary = collections.OrderedDict()
dictionary['integer_value'] = 1234567890
dictionary['float_value'] = 3.14
dictionary['string'] = 'The quick brown fox jumps over the lazy dog.'
dictionary['boolean_true'] = True
dictionary['boolean_false'] = False
dictionary['empty'] = None
dictionary['array'] = [0, 1, 2]
dictionary['object_0'] = object_0
encoded = json.dumps(dictionary, indent=2, cls=Encoder)
print('    encoded =')
print(encoded)
decoded = json.loads(encoded, cls=Decoder)
print('    decoded =')
print(decoded)
decoded_object_0 = decoded['object_0']
print('original object data = {}, {}, {}'.format(decoded_object_0.value_0, decoded_object_0.value_1, decoded_object_0.value_2.value))






