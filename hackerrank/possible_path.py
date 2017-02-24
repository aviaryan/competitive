from fractions import gcd

t = int(input())

for i in range(t):
	a,b,x,y = list(map(int, input().split()))
	# g1 = abs(a-x)
	# g2 = abs(b-y)
	# if (g1%b + g2%a == 0):
	# 	print("YES")
	# else:
	# 	print("NO")
	if (gcd(a,b) == gcd(x,y)):
		print("YES")
	else:
		print("NO")