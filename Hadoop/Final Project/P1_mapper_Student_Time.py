#!/usr/bin/python   

import sys
import csv


reader = csv.reader(sys.stdin, delimiter='\t')
    
for line in reader:
    if len(line) == 19:
        std = line[3]
        date = line[8].strip().split(" ")
        if len(date) > 1:
            hour = int(date[1].split(":")[0])
            print "{0}\t{1}".format(std, hour)
        


