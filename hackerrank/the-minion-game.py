s = input()
x = len(s)
j,p1,p2 = 0,0,0
v = ['A', 'E', 'I', 'O', 'U']

for i in s:
	if i in v:
		p2 += (x - j)
	else:
		p1 += (x - j)
	j+=1

if p1 > p2:
	print('Stuart', p1)
elif p2 > p1:
	print('Kevin', p2)
else:
	print('Draw')