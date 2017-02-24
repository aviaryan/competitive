from fractions import gcd

s = 720*7

for i in range(1, s+1):
	if s % i == 0:
		p = s/i
		if i >= p:
			break
		if gcd(i, p) == 1:
			print i, p

