#!/usr/bin/python
# Students and Posting Time on Forums
# reducer code
# output: std_id\tlist_of_max_hours
import sys

# empty dictionary of dictionary
# {key=std_id, value={key=hour, value=count}} 
dic = {}

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    std, hour = data_mapped
    # if std is alreay in dictionary
    if std in dic:
        # if hour is already in student dictionary
        if hour in dic[std]:
            dic[std][hour] = dic[std][hour] + 1
        # else insert 1 for hour
        else:
            dic[std][hour] = 1
    # else insert a new entry
    else:
        dic[std] = {hour: 1}

# go through each student record in dictionary
for std in dic:
    #find the hours as a list
    maximum = 0
    ans = []
    for h in dic[std]:
        if dic[std][h] > maximum:
            maximum = dic[std][h]
            ans = [h]
        # if we have two hours with same max hours 
        # then make a list
        elif dic[std][h] == maximum:
            ans = ans + [h]
    # sort the answer
    ans.sort(key = int)
    print "{0}\t{1}".format(std, ans)

   



