from math import factorial
a = int(input())
addend = 1
for j in range(1, a):
	addend = addend*2 + (j-1)
print(factorial(a) + addend)