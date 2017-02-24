n = int(input())
arr = list(map(int, input().split()))
dic = {}

for i in range(n):
	dic[arr[i]-1] = i+1

for i in range(n):
	print(dic[i])