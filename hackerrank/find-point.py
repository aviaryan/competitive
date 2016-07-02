t = int( input() )

for i in range(0,t):
	px, py, qx, qy = list(map(int, input().split()))
	print(2*qx - px, 2*qy - py)