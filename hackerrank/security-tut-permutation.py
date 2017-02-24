n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
	print(arr[arr[i]-1])