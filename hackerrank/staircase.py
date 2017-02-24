n = int(input())
# arr = list(map(int, input().split()))

for i in range(n):
	print(' ' * (n-i-1), end='')
	print('#' * (i+1))