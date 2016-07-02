import re

def isemailvalid(email):
	if re.search("^[\w\-]+@[a-zA-Z0-9]+\..{1,3}$", email) != None:
		return True
	else:
		return False

t = int(input())
lst = []

for i in range(0,t):
	lst.append(input())
lst = sorted(lst)
print( list( filter(isemailvalid, lst) ) )