a,b = input().split()

alen = len(a)
blen = len(b)
ct = 0
x = set()

for i in range(alen):
	for j in range(i,alen):
		x.add(a[i:j+1])

for i in x:
	if i.find(b) != -1:
		ct+=1

print(ct)