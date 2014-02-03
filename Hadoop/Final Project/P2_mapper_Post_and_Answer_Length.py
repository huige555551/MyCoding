#!/usr/bin/python   

import sys
import csv


reader = csv.reader(sys.stdin, delimiter='\t')
    
for line in reader:
    if len(line) == 19:
        nid, ntype, pid, abspid, msg = [line[0], line[5], line[6], line[7], line[4]]
        if ntype == 'question':
            print "{0}\t{1}\t{2}".format(nid, 'A', len(msg))
        elif ntype == 'answer':
            print "{0}\t{1}\t{2}".format(abspid, 'B', len(msg))


