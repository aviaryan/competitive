import re
MODULO = 1000000007

t = int(input())
c = 0

for i in range(t):
	s = input()
	if re.search("(?i)hackerrank", s) != None:
		c+=1

print(c)