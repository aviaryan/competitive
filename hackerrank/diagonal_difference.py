n = int(input())
d1, d2 = 0, 0

for i in range(n):
	arr = list(map(int, input().split()))
	d1 += arr[i] # 0 index
	d2 += arr[n-i-1]

print(abs(d2-d1))