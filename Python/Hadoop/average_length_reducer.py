#!/usr/bin/python
# Post and Answer Length Execise
# reducer code
# output: question_id\tquestion_length\tavg_answer_length    

import sys

#output format
print "{0}\t{1}\t{2}".format('question_id', 'question_length', 'avg_ans_length') 

#default value for vairables
pid = -1
qlen, alen, acount, avg_alen = [0, 0, 0, 0]

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 3:
        # Something has gone wrong. Skip this line.
        continue

    #read data from mapper output
    nid, ntype, nlen = data_mapped

    if pid != -1 and nid != pid:
        if acount != 0:
            avg_alen = float(alen) / int(acount)
        print "{0}\t{1}\t{2}".format(pid, qlen, round(avg_alen,2))
        qlen, alen, acount, avg_alen = [0, 0, 0, 0]

    if ntype == 'A': #if question
        qlen = int(nlen)
    elif ntype == 'B': #elif answer
        alen  += int(nlen)
        acount += int(1)
    #save the previous id
    pid = nid

#for the last id
if pid != -1:
    if acount != 0:
        avg_alen = float(alen) / int(acount) 
    print "{0}\t{1}\t{2}".format(pid, qlen, round(avg_alen,2))

   



