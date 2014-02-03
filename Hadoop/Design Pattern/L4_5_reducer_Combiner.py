#!/usr/bin/python

"""
Write a mapreduce program that processes the purchases.txt file and outputs
sum of sales for each weekday. Make sure that the logic that you use in reducer
code can be used to calculate intermediate value on mappers. Run the job by using
combiner. See notes for the exact syntax.

Look at the job details page for this job.

Q: What is the number of "Reduced inpurt records"?

"""

import sys
import datetime

salesTotal = 0
oldKey = None

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisSale = data_mapped

    if oldKey and oldKey != thisKey:
        print oldKey, "\t", salesTotal
        oldKey = thisKey;
        salesTotal = 0

    oldKey = thisKey
    salesTotal += float(thisSale)

if oldKey != None:
    print oldKey, "\t", salesTotal

