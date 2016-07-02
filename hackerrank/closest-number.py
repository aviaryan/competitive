MODULO = 1000000007

t = int(input())

for i in range(t):
	a,b,x = map(int, input().split())
	a = a**b
	z = a//x
	lm,um = z*x, (z+1)*x
	print( int( lm if (abs(lm-a) <= abs(um-a)) else um ) )