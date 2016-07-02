n = int(input())

for i in range(n):
    try:
        a,b = map(int, input().split())
    except ValueError as e:
        print("Error Code:", e)
        continue
    try:
        print(a//b)
    except ZeroDivisionError as e:
        print("Error Code:", e)
        