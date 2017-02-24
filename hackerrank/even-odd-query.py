MODULO = 1000000007

t = int(input())
arr = list(map(int, input().split()))
arr.append(1) # some non zero at end
q = int(input())

for i in range(q):
	x,y = map(int, input().split())
	if (x>y):
		print("Odd")
	elif (x == y):
		print( "Even" if (arr[x-1]%2 == 0) else "Odd" )
	else:
		if (arr[x-1]%2 == 0):
			if (arr[x] != 0):
				print("Even")
			else:
				print("Odd")
		else:
			print("Odd")