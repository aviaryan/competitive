a = int(input())
b = int(input())
c = int(input())
n = int(input())

out = []

for i in range(0,a+1):
	for j in range(0, b+1):
		for k in range(0, c+1):
			if i+j+k != n:
				out.append( [i, j, k] )

print(out)