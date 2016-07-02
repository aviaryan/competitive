n = int(input())
register = {}

for i in range(0, n):
	name, phy, che, math = list( input().split() )
	phy = float(phy)
	che = float(che)
	math = float(math)
	register[name] = (phy+che+math)/3

oname = input()
print( '{:.2f}'.format( register[oname] ) )