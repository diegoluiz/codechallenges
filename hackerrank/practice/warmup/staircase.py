#!/bin/python

import sys

n = int(raw_input().strip())

for i in range(1, n + 1):
	print("".ljust(n - i, " ") + "".rjust(i, "#"))