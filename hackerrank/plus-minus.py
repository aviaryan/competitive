num = int(input())
arr = list(map(int, input().split()))
p,n,z = 0,0,0

for i in arr:
	if i>0:
		p+=1
	elif i<0:
		n+=1
	else:
		z+=1

print(p/num)
print(n/num)
print(z/num)