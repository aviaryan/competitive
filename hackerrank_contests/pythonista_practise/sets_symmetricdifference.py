n = int(input())
nar = set( list( map( int, input().split() ) ) )

m = int(input())
mar = set( list( map( int, input().split() ) ) )

un = nar.union(mar)
ins = nar.intersection(mar)

j = sorted( un.difference(ins) )
for item in j:
	print(item)