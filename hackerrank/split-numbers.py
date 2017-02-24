import re

t = int(input())

for i in range(t):
	s = input()
	a,b,c = re.split("[\s-]", s)
	print('CountryCode=' + a + ',LocalAreaCode=' + b + ',Number=' + c)