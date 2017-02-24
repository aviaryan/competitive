import re
n = int(input())
for i in range(n):
    k = input()
    while re.findall('( \&\& )', k):
   		k = re.sub("( \&\& )", " and ", k, 1)
    while re.findall('( \|\| )', k):
   		k = re.sub("( \|\| )", " or ", k, 1)