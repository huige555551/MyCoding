#!/usr/bin/python

import sys
import csv

# Loop around the data
# It will be in the format key\tval
# Where key is the store name, val is the sale amount
#
# All the sales for a particular store will be presented,
# then the key will change and we'll be dealing with the next store

dictU = {}

reader = csv.reader(sys.stdin, delimiter='\t')
writer = csv.writer(sys.stdout, delimiter='\t', quotechar='"', quoting=csv.QUOTE_ALL)

for line in reader:
    if len(line) == 6:
        dictU[line[0]] = line[1:]
    elif len(line) == 21:
        if line[0] in dictU:
            newLine = line + dictU[line[0]]
            writer.writerow(newLine)
            print
        else:
            print 404
            writer.writerow(["404"]+ line)
            print 505
