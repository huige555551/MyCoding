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

for line in sys.stdin:
    data = line.strip().split("\t")
    if len(data) == 6:
        date, time, store, item, cost, payment = data        
        year, month, day = (int(x) for x in date.strip().split("-"))
        time = datetime.date(year, month, day)        
        print "{0}\t{1}".format(time.strftime("%a"), cost)


