#!/usr/bin/python   
# Students and Posting Time on Forums
# mapper code
# output: std_id\thour

import sys
import csv

reader = csv.reader(sys.stdin, delimiter='\t')
  
#read each row  
for line in reader:
    # if row is valid
    if len(line) == 19:
        #get student_id and date_time
        std = line[3]
        date = line[8].strip().split(" ")
        
        #if date has two elements
        if len(date) > 1:
            #get the hour
            hour = int(date[1].split(":")[0])
            #output: std_id\thour
            print "{0}\t{1}".format(std, hour)
        


