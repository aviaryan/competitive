

def factorial(n):
	return reduce(lambda x,y:x*y,[1]+range(1,n+1))

def ncr(n, r):
	return factorial(n) / (factorial(r) * factorial(n-r))


def myfunc(s):
	for n in range(1, s+1):
		for k in range(1, n):
			if (ncr(n, k) == s):
				print n, k


for i in range(124, 127):
	print ">>>", i
	myfunc(i)