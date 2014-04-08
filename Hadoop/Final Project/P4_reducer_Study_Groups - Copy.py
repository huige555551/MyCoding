#!/usr/bin/python

import sys

#output format
print "{0}\t{1}".format('question_id', 'user_list') 


userList = []
pid = None

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    nid, nusers = data_mapped
    if nid != pid and pid != None:
        print "{0}\t{1}".format(pid, userList)
        userList = []

    pid = nid
    userList.append(nusers)

if pid != None:
    print "{0}\t{1}".format(nid, userList)
