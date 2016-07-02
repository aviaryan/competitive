from math import floor,ceil
a = int(input())
b = int(input())
ispr = 0

for i in range(a, b+1):
    x = i*i
    x = str(x)
    slen = len(x)
    p1 = x[0:floor(slen//2)]
    if not p1:
    	p1 = 0
    else:
    	p1 = int(p1)
    p2 = int( x[ceil(slen//2):] )

    if i == p1+p2:
        print(i, end=' ')
        ispr = 1

if ispr == 0:
	print('INVALID RANGE')