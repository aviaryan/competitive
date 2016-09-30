a = map(int, input().split())
b = map(int, input().split())

asc = bsc = 0

for _ in range(3):
	if a[_] > b[_]:
		asc += 1
	elif b[_] > a[_]:
		bsc += 1

print asc, bsc