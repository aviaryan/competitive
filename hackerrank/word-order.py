from collections import Counter

n = int(input())
c = Counter()
s = []

for i in range(n):
	k = input()
	c[k]+=1
	s.append(k)

op = ''
ct = 0
for i in s:
	if c[i] == 0:
		continue
	op += str(c[i]) + ' '
	del c[i]
	ct+=1

print(ct)
print(op)