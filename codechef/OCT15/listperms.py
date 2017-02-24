from itertools import permutations

n=8

lis = permutations(range(1,n+1))

c = 0
for i in lis:
	c+=1
	if (c%24 == 0):
		print(c, i)