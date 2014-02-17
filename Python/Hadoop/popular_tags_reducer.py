#!/usr/bin/python
# Top Tags Exercise
# reducer code
# output: tag\tcount
# each mapper will send top 10 to reducer
# reducer will find the final top 10

import sys
import heapq

#output format
print "{0}\t{1}".format('tag', 'count') 

#heap for storing top 10
h = []

# maintain a heap of 10 elements
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

#print popular tags descendig order   
def print_top10(hh):
    if len(hh)==0: return
    data = heapq.heappop(hh)
    print_top10(hh)
    print "{0}\t{1}".format(data[1], data[0])


# call the functions
reducer()
print_top10(h)

