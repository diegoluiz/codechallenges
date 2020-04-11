#!/bin/python

import sys


#time = raw_input().strip()
time = "12:15:45PM"

h1 = time.split(":")[0]

if "AM" in time:
    time = time.replace("AM","")
    if h1 == "12":
        time = time.replace(h1,"00", 1)
    print(time)
    exit()
    
time = time.replace("PM","")
h2 = int(time.split(":")[0])
h3 = ""
if h2 == 12:
    h3 = "12"
else:
    h3 = str(h2 + 12)
    
time = time.replace(h1, h3, 1)
print(time)
