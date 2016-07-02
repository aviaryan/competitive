d = set()
ls = [5, 3, 1, 2, 6, 4, 7]
k = 2
nl = []
leng = len(ls)
_depth = 800


def solve(mls):
	recurse(mls, 0)
	makelist()

def recurse(cls, depth):
	global d
	if depth>_depth:
		return
	s = '+'.join(str(i) for i in cls)
	if s in d:
		return # dont recurse
	d.add(s)
	for i in range(leng-k+1):
		recurse( cls[0:i] + [cls[i+k-1]] + cls[i:i+k-1] + cls[i+k:] , depth+1)

def makelist():
	global nl
	nl = [i for i in d]
	nl.sort()


solve(ls)
nlc = nl
c = 0

for i in range(720):
	c = c+1
	# print(c, nlc[i])
	d = set()
	k = 3
	solve(nlc[i].split('+'))
	print(c, nlc[i], nl[0])
