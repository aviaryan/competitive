from pprint import pprint
from math import ceil


from functools import reduce
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""  
    return reduce(lcm, args)


d = {}
fc = 20

for i in range(1,fc):
	d[i] = {}
for i in range(1,fc):
	d[i][1] = i;

for n in range(2,fc):
	for k in range(2, n+1):
		d[n][k] = ceil( d[n-1][k-1]*d[n][k-1] / (d[n][k-1] - d[n-1][k-1]) )

for i in range(1,fc):
	s = 1
	for k in range(1,i+1):
		# d[i][k] = int(d[i][k]/i)
		d[i][k] = lcm(d[i][k], s)
		s = d[i][k]


for i in d:
	print(i, ':', end=' ')
	for j in d[i]:
		print(d[i][j], end=' ')
	print()