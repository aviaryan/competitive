n,k = map(int, input().split())
a = sorted( set( map(int, input().split()) ) )
ans = 0
for i in a:
	if i+k in a:
		ans+=1
print(ans)
# or c++ double set tech . for each elem insert its ai+k.
# then 2n - len(double set) is the ans