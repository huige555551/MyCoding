#!/usr/bin/python

"""
Write a mapreduce program that processes the purchases.txt file and outputs 
mean (average) of sales for each weekday.

Q: What is the mean value of sales on Sunday?

Note: should have passed only sundays' data to reducer
"""

import sys
import datetime

salesTotal = 0
oldKey = None

#dictionary of sales and count for each weekday
dSales = {'Sat': 0, 'Sun': 0, 'Mon': 0, 'Tue': 0, 'Wed': 0, 'Thu': 0, 'Fri': 0}
dCount = {'Sat': 0, 'Sun': 0, 'Mon': 0, 'Tue': 0, 'Wed': 0, 'Thu': 0, 'Fri': 0}

#method for storing data in dictionary
def storeDic(oldKey, salesTotal):
    weekday = datetime.datetime.strptime(oldKey,"%Y-%m-%d").strftime("%a")
    dSales[weekday] = dSales[weekday] + salesTotal
    dCount[weekday] = dCount[weekday] + 1
    return

#main reducer code
for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisSale = data_mapped

    if oldKey and oldKey != thisKey:
        print oldKey, "\t", salesTotal
        storeDic(oldKey, salesTotal)
        oldKey = thisKey;
        salesTotal = 0

    oldKey = thisKey
    salesTotal += float(thisSale)

if oldKey != None:
    print oldKey, "\t", salesTotal
    storeDic(oldKey, salesTotal)

# print the dictionary
print dSales
print dCount

#calculate mean sales
for w in dSales:
    print "{0}\t{1}".format(w, float(dSales[w]/dCount[w]))
