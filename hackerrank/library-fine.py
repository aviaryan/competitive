d1,m1,y1 = list(map(int, input().split()))
d2,m2,y2 = list(map(int, input().split()))

f = 0
if (y1 > y2): f = 10000
elif (y1 == y2):
	if (m1 > m2): f = 500 * (m1-m2)
	elif (m1 == m2):
		if (d1 > d2): f = 15 * (d1-d2)

print(f)