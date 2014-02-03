#!/usr/bin/python

"""
Q: List of comma separated nodes the word "fantastically" can be found 
   in (Please list the nodes in ascending order, i.e. 1, 2, 3, 4, 5)
"""
import sys

#list of nodes 
data = []

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisCount = data_mapped    
    data.append(long(thisKey))

#for ascending order
data.sort()

string = ""
for d in data:
    string += str(d) + ","

#print list of nodes as string
print string

