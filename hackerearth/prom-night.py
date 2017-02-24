t = int( input() )

for i in range(0,t):
	m,n = list( map(int, input().split()) )
	boys = sorted( list(map(int, input().split())) )
	girls = sorted( list(map(int, input().split())) )
	if m>n:
		print("NO")
	else:
		suc = 1
		for j in range(m):
			if girls[j] >= boys[j]:
				suc = 0
				break
		if suc==0:
			print("NO")
		else:
			print("YES")