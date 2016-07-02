t = int(input())

clas = []
marks_list = []
maax = 0.0

for _ in range(0,t):
	name = input()
	marks = float(input())
	clas.append( [name, marks] )
	marks_list.append(marks)

marks_list = sorted(marks_list)
j = marks_list[0]

for k in range(1, len(marks_list)):
	if marks_list[k] != j:
		break

final = sorted([student[0] for student in clas if student[1] == marks_list[k]])

for item in final:
	print(item)