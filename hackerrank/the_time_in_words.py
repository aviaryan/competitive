def num2str(num):
	if (num>20):
		sr = ts[int(num/10)] + " " + uk[num%10]
	else:
		sr = uk[num]
	return sr


h = int(input())
m = int(input())

uk = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen", 20: "twenty"}
ts = {2: "twenty", 3: "thirty", 4: "fourty", 5: "fifty"}

if (m==0):
	print(uk[h], "o' clock")
elif (m==15):
	print("quarter past", uk[h])
elif (m==30):
	print("half past", uk[h])
elif (m==45):
	print("quarter to", uk[(h%12) + 1])
elif (m<30):
	print(num2str(m), "minutes past", uk[h])
else:
	print(num2str(60-m), "minutes to", uk[(h%12) + 1])