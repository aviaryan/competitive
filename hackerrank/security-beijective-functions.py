n = int(input())
arr = list(map(int, input().split()))

for i in range(1,n+1):
	if i in arr:
		arr.remove(i)

if (len(arr) == 0):
	print("YES")
else:
	print("NO")