#!/usr/bin/python

"""
Write a mapreduce program that processes the purchases.txt file and outputs 
mean (average) of sales for each weekday.

Q: What is the mean value of sales on Sunday?

Note: should pass only sundays' data to reducer
"""

import sys
import datetime

for line in sys.stdin:
    data = line.strip().split("\t")
    if len(data) == 6:
        date, time, store, item, cost, payment = data        
        year, month, day = (int(x) for x in date.strip().split("-"))
        time = datetime.date(year, month, day)        
        print "{0}\t{1}".format(time, cost) #time.strftime("%a"), cost)


