#!/bin/python

import sys

def Process(case):
    r2 = sum([x for x in case if x > 0])
    
    res = []
    s = 0
    for i in range(0, len(case)):
        for j in range(i, len(case)):
            s += case[j]
            res.append(s)
        s = 0
    
    r1 = 0
    if (len(res) != 0):
        r1 = max(res)
        
    if (r1 < 0):
        r1 = 0
        
    print(str(r1) + " " + str(r2))

cases = []
#n = int(raw_input().strip())
#for i in xrange(n):
#   c_n = int(raw_input().strip())
#   c_a = map(int,raw_input().strip().split(' '))
#   cases.append(c_a)

n = 2
cases = [
    [1, 2, 3, 4], 
    [2, -1, 2, 3, 4, -5],
    [],
    [-1,-2,-3,-4]
    ]

for case in cases:
    Process(case)    