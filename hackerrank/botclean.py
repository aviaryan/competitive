#!/usr/bin/python

# Head ends here
def next_move(posr, posc, board):

	if board[posr][posc] == 'd':
		return 'CLEAN'
	if posr%2 == 0:
		r = board[posr].rfind('d')
		if r>posc:
			return 'RIGHT'
		k = board[posr+1].rfind('d')
		if k>posc:
			return 'RIGHT'
		if r==-1 and posr<4:
			return 'DOWN'
	else:
		r = board[posr].find('d')
		if r<posc and r!=-1:
			return 'LEFT'
		k = board[posr+1].find('d')
		if k<posc and k!=-1:
			return 'LEFT'
		if r==-1 and posr<4:
			return 'DOWN'


# Tail starts here
if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [str(input().strip()) for i in range(5)]
    board.append('-----')
    print( next_move(pos[0], pos[1], board) )