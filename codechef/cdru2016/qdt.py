from math import log, ceil
import operator as op


def factorial(n):
	return reduce(lambda x,y:x*y,[1]+range(1,n+1))

def iroot(k, n):
    u, s = n, n+1
    while u < s:
        s = u
        t = (k-1) * s + n // pow(s, k-1)
        u = t // k
    return s

def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, xrange(n, n-r, -1))
    denom = reduce(op.mul, xrange(1, r+1))
    return numer//denom


t = int(input())


for i in range(t):
	n = int(input())
	k = int(ceil(log(n)))
	for i in range(1, k+1):
		lb = iroot( i, (factorial(k) * n) )
		for j in range(lb-1, lb+k+2):
			if ncr(j, i) == lb:
				s = '(' + str(j) + ',' + str(i) + ')'
				print s
	print ''