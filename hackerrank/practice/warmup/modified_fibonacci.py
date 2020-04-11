#!/bin/python
import sys
import math

#input = map(int,raw_input().strip().split(' '))

input = [0,1,10]

a = input[0]
b = input[1]
n = input[2]

r = 0
for i in range(2,n):
    r = float(math.pow(b,2)) + a
    a = b
    b = r
    print(int(r))
    
print(int(r))