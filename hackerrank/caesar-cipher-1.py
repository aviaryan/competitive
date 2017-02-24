n = int(input())
s = input()
k = int(input())

f = []

for i in range(n):
	c = s[i]
	p = ord(c)
	if c.isalpha():
		if (p < 96): d=64
		else: d=96
		p -= d
		p = (p+k-1)%26 + 1
		p += d
	f.append(p)

print( "".join(chr(i) for i in f) )