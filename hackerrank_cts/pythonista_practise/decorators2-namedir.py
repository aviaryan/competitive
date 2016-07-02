import operator

t = int(input())

dr = []
for i in range(0,t):
	j = list( input().split() )
	dr.append(j)

byage = operator.itemgetter(2)
dr = sorted(dr, key=byage)

for human in dr:
	if human[3] == 'M':
		s = "Mr."
	else:
		s = "Ms."
	print(s, human[0], human[1])