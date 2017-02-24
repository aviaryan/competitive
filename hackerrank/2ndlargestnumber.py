n = int(input())
max1, max2 = -101, -101

j = sorted( list( map( int, input().split() ) ) )
for item in j: # this works as array sorted
	if (item>max1):
		max2 = max1
		max1 = item

print(max2)