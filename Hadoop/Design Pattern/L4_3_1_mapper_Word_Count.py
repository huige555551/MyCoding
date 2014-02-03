#!/usr/bin/python

"""
Q: How many times was the word "fantastic" used on forums?

Write a MapReduce program that creates an index of all words that can be 
find in the body of a forum post and node id they can be found in.

Do not parse the HTML, just split the text on all whitespace, as well as
the following characters: .!?:;"()<>[]#$=-/

"""

import sys
import re

word = 'fantastic'

tabCount = 0
for line in sys.stdin:
    data = re.split('\"\t\"', line)
	
	# one row consists of 19 column
	# one row can be spread over multiple lines
	# "import csv" is the easier way to parse row by row
    if len(data) != 19 and tabCount == 0:
        temp = data
        tabCount += len(temp)
    elif len(data) != 19 and tabCount != 0:
        temp[len(temp)-1] += data[0]
        if len(data) > 1:
            temp += data[1:]
            tabCount += len(data)-1
        if len(temp) == 19:
            data = temp
            tabCount = 0
    
    if len(data) == 19:
        nid = data[0][1:]
        body = data[4]

        data = re.split('\s|\.|\!|\?|\:|\;|\"|\(|\)|\<|\>|\[|\]|\#|\$|\=|\-|\/|\,', body.lower())
        count = data.count(word)
        if count > 0:
            print "\n{0}\t{1}\n".format(word, count)

#\s|\.|\!|\?|\:|\;|\"|\(|\)|\<|\>|\[|\]|\#|\$|\=|\-|\/|\,
