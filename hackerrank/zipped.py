n,m = map(int, input().split())
f = list()
for i in range(m):
    a = list(map(float,input().split()))
    f += [a]
    
fz = zip(*f)
for item in fz:
    print( sum(i for i in item) / m )