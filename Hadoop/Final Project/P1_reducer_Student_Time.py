#!/usr/bin/python

import sys

dic = {}

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    std, hour = data_mapped
    if std in dic:
        if hour in dic[std]:
            dic[std][hour] = dic[std][hour] + 1
        else:
            dic[std][hour] = 1
    else:
        dic[std] = {hour: 1}

for std in dic:
    maximum = 0
    ans = []
    for h in dic[std]:
        if dic[std][h] > maximum:
            maximum = dic[std][h]
            ans = [h]
        elif dic[std][h] == maximum:
            ans = ans + [h]
    ans.sort(key = int)
    print "{0}\t{1}".format(std, ans)
    #print "{0}\t{1}".format(std, dic[std])
    

   



