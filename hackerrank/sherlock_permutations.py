t = int(input())
MODULO = 1000000007

def PowMod(a, n):
	x = 1
	while (n>0):
		if (n & 1 == 1): x = (x*a)%MODULO
		a = (a*a) % MODULO
		n >>= 1
	return x % MODULO


fact = [1,1]

for i in range(2, 2001):
	fact.append( (i * fact[i-1]) % MODULO )

for i in range(t):
	n,m = list(map(int, input().split()))
	ans = fact[n+m-1] * PowMod( (fact[m-1] * fact[n]) % MODULO , MODULO-2 )
	print( ans % MODULO )