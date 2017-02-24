a,b,n = list(map(int, input().split()))

pre = b*b + a
for i in range(0, n-2):
	b, pre = pre, pre*pre+b

print(b)