
def gcd(a, b):
	while b:
		a, b = b, a%b
	return a


for i in range(1, 20):
	s = 0
	for j in range(1, i+1):
		s += (i/gcd(i,j))
	print(i, s)