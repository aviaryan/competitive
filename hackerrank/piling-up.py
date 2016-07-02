t = int(input())

for i in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	p = 2**32
	e = 0
	for k in range(1,n+1):
		if (a[0] > a[n-k]):
			if p >= a[0]:
				p = a[0]
				del a[0]
			else:
				e = 1
				break
		else:
			if p >= a[n-k]:
				p = a[n-k]
				del a[n-k]
			else:
				e = 1
				break
	print("Yes" if e==0 else "No")