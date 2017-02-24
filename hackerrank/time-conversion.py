a,b,c = list(input().split(":"))
c,d = c[:2], c[-2:]
a = int(a)

if (a == 12):
	if (d == 'AM'):
		a = 0
elif (d == 'PM'):
	a = (a+12)%24

print("{:02d}".format(a), end='')
print(':'+b+':'+c)