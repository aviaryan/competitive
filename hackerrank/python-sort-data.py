n,m = map(int, input().split())
a = list()
for i in range(n):
    a.append( list(map(int, input().split())) )
k = int(input())
a.sort(key = lambda row : row[k])
for i in a:
    for j in i:
        print(j, end=' ')
    print()