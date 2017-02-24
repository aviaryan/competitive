
def getin():
	while True:
		line = input().strip()
		if not line:
			pass
		else:
			return line

for i in range(int(input())):
	s = getin()
	if s.find("LOL") > -1:
		print('Ban it!')
	else:
		print('Dont ban it!')