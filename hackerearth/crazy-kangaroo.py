MODULO = 1000000007

t = int(input())

for i in range(t):
	a,b,c = map(int, input().split())
	z = b-a+1
	ans = z//c
	