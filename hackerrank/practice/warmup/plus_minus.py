#!/bin/python

import sys


#n = int(raw_input().strip())
#arr = map(int,raw_input().strip().split(' '))

n = 6
arr = [-4, 3, -9, 0, 4, 1]

r1 = [x for x in arr if x < 0]
r2 = [x for x in arr if x == 0]
r3 = [x for x in arr if x > 0]

print(round(float(len(r3)) / len(arr), 6))
print(round(float(len(r1)) / len(arr), 6))
print(round(float(len(r2)) / len(arr), 6))

