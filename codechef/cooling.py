t = int( input() )

for i in range(0,t):
	n = int( input() )
	pie = sorted( list(map(int, input().split())) )
	pans = sorted( list(map(int, input().split())) )
	#print(pans)
	#print(pie)
	k , panspos = 0, 0
	for j in range(n, 0, -1):
		if pans[n-1-panspos] >= pie[j-1]:
			k=k+1
			panspos = panspos+1
	print(k)