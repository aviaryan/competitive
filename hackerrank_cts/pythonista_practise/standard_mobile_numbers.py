t = int(input())

lst = []

for i in range(0,t):
	a = input()
	lst.append( a[-10:] )

lst = sorted( lst )
for item in lst:
	print("+91", item[0:5], item[5:])