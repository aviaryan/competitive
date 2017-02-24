from math import factorial as f
for _ in range(int(input())):
	a=float(input())
	s,c=0,0
	for i in range(5): k=pow(-1,i);p=2*i+1;s+=k*a**p/f(p);c+=k*a**(p-1)/f(p-1)
	print("{:.3f}\n{:.3f}".format(s,c))