n = int(input())

for i in range(n):
	s = input().split()
	i  = (s[0] == s[2] or s[1] == s[2] or s[0] == s[3] or s[1] == s[3])
	i *= (s[2] == s[4] or s[3] == s[4] or s[2] == s[5] or s[3] == s[5])
	print("YES" if i else "NO")