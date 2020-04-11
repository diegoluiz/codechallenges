#!/bin/python

import sys

n = 3
a = [[11, 2, 4], [4, 5, 6], [10, 8, -12]]

#n = int(raw_input().strip())
#for a_i in xrange(n):
#   a_temp = map(int,raw_input().strip().split(' '))
#   a.append(a_temp)

d1 = 0
d2 = 0
c = 0
for i in a:
    d1 += i[c]
    d2 += i[len(i) - 1 - c]
    c = c + 1

print(abs(d1 - d2))