def noOfDaysTaken(vacState):
	daysTaken = 0
	lenStalls = len(vacState)
	while True:
		pointer = 0
		changes_this_iter = 0
		while True:
			if pointer >= lenStalls-1:
				# out of bounds
				break
			if vacState[pointer] == 0 and vacState[pointer+1] == 1:
				vacState[pointer] = 1
				vacState[pointer+1] = 0
				pointer += 2
				changes_this_iter += 1
			else:
				pointer += 1
		daysTaken += 1
		if changes_this_iter == 0:
			break
	return daysTaken - 1


def noOfDaysTaken(vacState):
	daysTaken = 0
	lenStalls = len(vacState)
	while True:
		pointer = 0
		changes_this_iter = 0
		while True:
			if pointer >= lenStalls-1:
				# out of bounds
				break
			if vacState[pointer] == 0 and vacState[pointer+1] == 1:
				vacState[pointer] = 1
				vacState[pointer+1] = 0
				pointer += 2
				changes_this_iter += 1
			else:
				pointer += 1
		daysTaken += 1
		if changes_this_iter == 0:
			break
	return daysTaken - 1


## other stuff
arr = [1, 0, 0, 0, 1, 1, 1]
# arr = [1, 1, 1, 1, 0, 0, 0]
# arr = [0, 1, 0, 1, 1]
print(noOfDaysTaken(arr))
