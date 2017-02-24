n = int( input() )
mnx, mny = 1000001, 1000001

for i in range(0,n):
	x,y = list(map(int, input().split()))
	if (x<mnx):
		mnx = x
	if (y<mny):
		mny = y

print(mnx * mny)