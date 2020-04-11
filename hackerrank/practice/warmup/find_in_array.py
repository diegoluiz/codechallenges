#!/bin/python
import sys


value = int(raw_input().strip())
size = int(raw_input().strip())
arr = map(int,raw_input().strip().split(' '))

print(arr.index(value))