from collections import deque

d = set()
q = deque()
ls = [2, 3, 1, 4, 5]
# ls = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# 2 3 1 4 5
k = 3
nl = []
leng = len(ls)
_depth = 990

# 128242

def solve(mls):
	qrecurse(mls)
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

def qrecurse(cls):
	q.append(cls)

	while (len(q) > 0):
		cls = q[0]
		s = '+'.join(str(i) for i in cls)
		if s in d:
			q.popleft()
			continue
		d.add(s)
		for i in range(leng-k+1):
			q.append( cls[0:i] + [cls[i+k-1]] + cls[i:i+k-1] + cls[i+k:] )
		q.popleft()


def makelist():
	global nl
	nl = [i for i in d]
	nl.sort()


solve(ls)
c = 0
for i in nl:
	c = c+1
	print(c, i)