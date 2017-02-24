
dc = dict()

def desfac(n):
	for i in range(2,n):
		if n%i == 0:
			dc[i] = 0

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
span = zer+one
ans = 0

for i in range(1, span+1): # all allowed
	dc[i] = 1

for i in range(span-1, 0, -1):
	if span%i == 0 and dc[i] == 1:
		divs = int(span/i)
		if zer%divs == 0 and one%divs == 0:
			zc = int(zer / divs)
			oc = int(one / divs)
			if zc+oc == i:
				ans += int(fac(i) / (fac(zc) * fac(oc)))
				desfac(i)
ans %= md

if ans>1:
	if zer==0 or one==0:
		ans = 1

print(ans)