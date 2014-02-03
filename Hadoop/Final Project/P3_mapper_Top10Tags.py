#!/usr/bin/python   

import sys
import csv
import heapq

reader = csv.reader(sys.stdin, delimiter='\t')

h = [] 
d = {}
  
for line in reader:
    if len(line) == 19:     
        tagList = line[2].split()
        for t in tagList:
            if t in d:
                d[t] += 1
            else:
                d[t] = 1

for t in d:
    if len(h) < 10:
        h.append( (int(d[t]), t) )
        if len(h) == 10:
            heapq.heapify(h)
    elif len(h) == 10:
        mini = h[0][0]
        if int(d[t]) > mini:
            heapq.heappop(h)
            heapq.heappush(h, (int(d[t]), t))

loopCount = min(len(h), 10)

for i in range(loopCount):
    data = heapq.heappop(h)
    print "{0}\t{1}".format(data[1], data[0])

