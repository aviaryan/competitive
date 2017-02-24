
def next_move(x, y, board):
	if board[x][y] == 'd':
		return 'CLEAN'
	for i in range(5):
		if board[i].find('d') > -1:
			p = board[i].find('d')
			break
	if y > p:
		return 'LEFT'
	elif y < p:
		return 'RIGHT'
	elif x < i:
		return 'DOWN'
	else:
		return 'UP'

if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [str(input().strip()) for i in range(5)]
    board.append('-----')
    print( next_move(pos[0], pos[1], board) )