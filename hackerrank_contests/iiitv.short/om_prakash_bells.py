import math
t = int(input())
while t>0:
	n = int(input())
	x = math.factorial(2*n)//(math.factorial(n)*math.factorial(n+1))
	x = int(x)
	print((x)%1000000007)
	t-=1
