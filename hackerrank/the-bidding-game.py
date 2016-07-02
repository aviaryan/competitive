#!/bin/python3
def calculate_bid(player,scotch_pos,first_moves,second_moves):
	if player==1:
		dif = scotch_pos-0
		myleft = 100 - sum(first_moves)
		theyleft = 100 - sum(second_moves)
	else:
		dif = 10 - scotch_pos
		myleft = 100 - sum(second_moves)
		theyleft = 100 - sum(first_moves)

	

    return 5

#gets the id of the player
player = int(input())
scotch_pos = int(input())         #current position of the scotch

first_moves = map(int, input().split())
second_moves = map(int, input().split())
bid = calculate_bid(player,scotch_pos,first_moves,second_moves)
print(bid)