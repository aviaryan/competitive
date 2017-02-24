
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def fac(a):
	s = 1
	for i in range(2,a+1):
		s *= i
	return s

zer = int(input())
one = int(input())
md = 10**7+1


hcf = gcd(zer, one)
if hcf==0:
	hcf=1
zerl = int(zer/hcf)
onel = int(one/hcf)
sz = zerl + onel
x = int( fac(sz) / (fac(zerl) * fac(onel)) )
if sz < (zer+one):
	print(x % md)
else:
	print(0)