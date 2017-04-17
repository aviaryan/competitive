t = int(input())

lst = []
if t>0:
	lst.append(0)
if t>1:
	lst.append(1)
x1, x2 = 0, 1

for j in range(2,t):
	x1, x2 = x2, x1+x2
	lst.append(x2)

lst = list( map( lambda x:x*x*x, lst ) )

print(lst)