#!/usr/bin/python

import sys
import heapq

#output format
print "{0}\t{1}".format('tag', 'count') 

#heap for storing top 10
h = []

def insert_into_heap(tag, count):
    if len(h) < 10:
        h.append( (int(count), tag) )
        if len(h) == 10:
            heapq.heapify(h)
    elif len(h) == 10:
        mini = h[0][0]
        if count > mini:
            heapq.heappop(h)
            heapq.heappush( h, (int(count), tag) )

def reducer():
    ptag = None
    total_count = 0

    for line in sys.stdin:
        data_mapped = line.strip().split("\t")
        if len(data_mapped) != 2:
            # Something has gone wrong. Skip this line.
            continue

        #read data from mapper output
        ntag, ncount = data_mapped

        if ptag and ntag != ptag:
            insert_into_heap(ptag, total_count)
            total_count = 0

        #save the previous tag
        ptag = ntag
        total_count += int(ncount)

    #for the last tag
    if ptag != None:
        insert_into_heap(ptag, total_count)

   
def print_top10():
    loopCount = min(len(h), 10)

    for i in range(loopCount):
        data = heapq.heappop(h)
        print "{0}\t{1}".format(data[1], data[0])



reducer()
print_top10()

