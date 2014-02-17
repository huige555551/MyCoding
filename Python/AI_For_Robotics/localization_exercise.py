colors = [['red', 'green', 'green', 'red' , 'red'],
          ['red', 'red', 'green', 'red', 'red'],
          ['red', 'red', 'green', 'green', 'red'],
          ['red', 'red', 'red', 'red', 'red']]

measurements = ['green', 'green', 'green' ,'green', 'green']


motions = [[0,0],[0,1],[1,0],[1,0],[0,1]]

sensor_right = 0.7

p_move = 0.8

def show(p):
    for i in range(len(p)):
        print p[i]

#DO NOT USE IMPORT
#ENTER CODE BELOW HERE
#ANY CODE ABOVE WILL CAUSE
#HOMEWORK TO BE GRADED
#INCORRECT

# uniform distribution
p = []
total_size = len(colors) * len(colors[0])
for i in range(len(colors)):
    p.append([1.0/total_size] * len(colors[0]))

def move(p, m):
    q = []
    
    for i in range(len(p)):
        q.append([])
        for j in range(len(p[i])):
            s  = p[ (i-m[0]) % len(p) ][ (j-m[1]) % len(p[i]) ] * p_move
            s += p[i][j] * (1-p_move)
            q[i].append( s ) 
    return q           

def sense(p, s):
    total = 0.0
    for i in range(len(colors)):
        for j in range(len(colors[i])):
            hit = (colors[i][j] == s)
            p[i][j] *= (hit * sensor_right + (1-hit)*(1-sensor_right))                
        total += sum(p[i])
            
    for i in range(len(p)):
        for j in range(len(p[i])):
            if total != 0:
                p[i][j] = p[i][j] / total
    return p

for m in range(len(motions)):
    p = move(p, motions[m])
    p = sense(p, measurements[m])

     
#Your probability array must be printed 
#with the following code.

show(p)




