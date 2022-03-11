import random

n = 1000000

f = open("input", "w")

def gen(type):
    a = []
    for _ in range(n):
        a.append(random.uniform(- 1000000, 1000000))
    
    if (type == 0):
        a.sort()
    elif (type == 1):
        a.sort(reverse = True)

    f.write(str(n) + ' ')
    for x in a:
        f.write("{0:.3f} ".format(x))
    f.write('\n')

for i in range(10):
    gen(i)