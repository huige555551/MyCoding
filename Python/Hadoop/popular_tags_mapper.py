#!/usr/bin/python   
# Top Tags Exercise
# mapper code
# output: tag\tcount
# each mapper will send top 10 to reducer

import sys
import csv
import heapq

reader = csv.reader(sys.stdin, delimiter='\t')

#heap = h
h = [] 
#dictionary = d
d = {}
  
for line in reader:
    if len(line) == 19:     
        tagList = line[2].split()
        #store tags in dictionary
        for t in tagList:
            if t in d:
                d[t] += 1
            else:
                d[t] = 1
                
#for each entry in dictionary
for t in d:
    # if len of heap is less than 10
    # no need to heapify or sort them
    if len(h) < 10:
        h.append( (int(d[t]), t) )
        # if len is 10 then make heap
        if len(h) == 10:
            heapq.heapify(h)
    # always maintain a heap of size 10
    # by removing the lowest value
    elif len(h) == 10:
        mini = h[0][0]
        if int(d[t]) > mini:
            heapq.heappop(h)
            heapq.heappush(h, (int(d[t]), t))

#print result
loopCount = min(len(h), 10)

for i in range(loopCount):
    data = heapq.heappop(h)
    print "{0}\t{1}".format(data[1], data[0])

