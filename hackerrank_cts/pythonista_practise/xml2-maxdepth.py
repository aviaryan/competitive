import xml.etree.ElementTree as etree

def maxxmldepth( tag, depth ):
	maxdepth = depth
	for child in tag:
		k = maxxmldepth(child, depth+1)
		if k>maxdepth:
			maxdepth=k
	return maxdepth


n = int(input())
s = ""

for i in range(0,n):
	s = s + input()
	s += '\n'

root = etree.fromstring(s)

md = maxxmldepth(root, 0)
print(md)