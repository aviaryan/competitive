n = 3
c = 3
strs = []

for i in range(0, 2**n):
	strs.append(('{0:0' + str(n) + 'b}').format(i))

#print(strs)

strconv = strs[:]

#print(strconv)

for i in range(len(strconv)):
	strconv[i] = strconv[i].replace('1', 'g').replace('0', 'l')

#print(strconv)

strm = strconv[:]

for i in range(c-1):
	for i in range(len(strconv)):
		strm[i] = strm[i].replace('g', 'g'*n).replace('l', strconv[i])

for i in strm:
	print(i[:200])