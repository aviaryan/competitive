import re

t = int(input())

for i in range(0,t):
	z = input()
	if len(z) == 10:
		if re.search("^[789]\d+$", z) != None:
			print("YES")
		else:
			print("NO")
	else:
		print("NO")