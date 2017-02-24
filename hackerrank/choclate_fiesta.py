t = int(input())
MODULO = 1000000007

def PowMod(a, n):
	x = 1
	while (n>0):
		if (n & 1 == 1): x = (x*a)%MODULO
		a = (a*a) % MODULO
		n >>= 1
	return x % MODULO

arr = list(map(int, input().split()))
e,o = 0,0
for i in arr:
	if (i%2 == 0): e+=1
	else: o+=1

ans = (PowMod(2, e)-1 + MODULO) % MODULO
if (o>1):
	ans = ( ((ans+1) * PowMod(2, o-1))%MODULO -1 + MODULO ) % MODULO # for o=n, nc0 + nc2 + nc4 ....
	# ans + 1 to handle the absent even case

print(ans)