from collections import Counter
c = Counter(input())
for i in range(3):
	j = c.most_common()[0]
	for char in 'abcdefghijklmnopqrstuvwxyz':
		if c[char] == j[1]:
			break
	print(char, c[char])
	del c[char]