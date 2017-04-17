for i in range(int(input())):
	s=0.0
	for j in range(int(input())): s+=pow(-1,j)/(2*j+1)
	print('{:.15f}'.format(s))