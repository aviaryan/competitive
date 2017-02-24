import xml.etree.ElementTree as etree

def calcscore( tag ):
	ct = len( tag.attrib )
	for child in tag:
		ct += calcscore(child)
	return ct



n = int(input())
s = ""

for i in range(0,n):
	s = s + input()
	s += '\n'

root = etree.fromstring(s)

ct = calcscore(root)
print(ct)