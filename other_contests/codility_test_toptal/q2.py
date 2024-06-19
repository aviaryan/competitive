# import os


def is_valid_x_y(x, y, n):
	return (x >= 0) and (x <= n-1) and (y >= 0) and (y <= n-1)


def solve(filename):
	fp = open(filename, 'r')
	data = fp.read()
	rows = data.split('\n')
	for i in range(len(rows)):
		rows[i] = rows[i].split(' ')
	# print(rows)
	n = len(rows)
	# make the solution
	xy = [-1, 0, 1]
	ans = [[0 for i in range(n)] for i in range(n)] # copy
	# print(ans)
	for i in range(n):
		for j in range(n):
			if rows[i][j] == 'X':
				ans[i][j] = 'X'
				continue
			# make solution for each cell
			ans[i][j] = 0
			for a in range(3):
				for b in range(3):
					if a == 1 and b == 1:  # 0, 0
						pass
					if is_valid_x_y(i + xy[a], j + xy[b], n) and rows[i + xy[a]][j + xy[b]] == 'X':
						ans[i][j] += 1
	# return solution
	return ans


if __name__ == '__main__':
	ans = solve('msw.txt')
	print('\n\nPrinting Solution now')
	for a in ans:
		print(a)
