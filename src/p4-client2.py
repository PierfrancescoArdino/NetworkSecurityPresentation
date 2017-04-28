#!/usr/bin/python2

prefix = 'A' * 1000

pattern = ''
for i in range(0, 15):
   for j in range(0, 10):
      pattern += str(i) + str(j)

print prefix + pattern
