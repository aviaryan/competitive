n = int(input())
arr = list(map(int, input().split()))
s=1

for i in range(n):
	if (arr[arr[i]-1] != (i+1)):
		s=0
		break

if (s==1): print("YES")
else: print("NO")