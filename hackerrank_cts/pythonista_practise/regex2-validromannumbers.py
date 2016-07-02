import re

z = input()
b = re.match("[CDMLXVI]+", z) != None
if b:
	tens = "IXCM"
	fives = "VLD"
	for j in range(len(tens)):
		if b:
			b = re.search(tens[j]*4, z) == None
	for j in range(len(fives)):
		if b:
			b = re.search(fives[j]*2, z) == None

print(b)