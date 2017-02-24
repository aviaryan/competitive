MODULO = 1000000007

t = int(input())

def PowMod(a, n):
	x = 1
	while (n>0):
		if (n & 1 == 1): x = (x*a)%MODULO
		a = (a*a) % MODULO
		n >>= 1
	return x % MODULO


for i in range(t):
	a,b = map(int, input().split())
	print(PowMod(a % MODULO, b % (MODULO-1)))