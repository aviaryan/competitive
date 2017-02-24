import subprocess


for i in range(0, 10):
	for j in range(0, 10):
		big = subprocess.check_output("python good-words.py < input.txt")
		sm = subprocess.check_output("python good-words2.py < input.txt")
		print(big)