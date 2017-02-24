# reasons of failure - wrong logic

def getin():
	while True:
		line = input().strip()
		if not line:
			pass
		else:
			return line


t = int(getin())

for i in range(t):
	n,m = map(int, getin().split())
	# debug code
	if n<1 or m<1:
		pa = throwerror

	ts = 0
	for j in range(n):
		ls = [ int(10000*float(temp)) for temp in getin().split() ]
		s = 1
		for k in range(m):
			s = s * ls[k]
		if j==0:
			sj = s
		ts = ts + s

	if ts==0:
		ans = 0.000000
	else:
		ans = float( sj/ts )
	print( "{:.10f}".format(ans) )