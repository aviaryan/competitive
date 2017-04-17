sparent = input()
schild = input()

count = 0
ind = 0
while 2>1:
	ind = sparent.find( schild, ind )
	if ind>-1:
		count+=1
		ind+=1
	else:
		break

print( count )