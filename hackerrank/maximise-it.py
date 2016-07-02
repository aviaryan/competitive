k, m = map(int, raw_input().split())
import itertools
ls = []
for _ in xrange(k):
    ls.append(map(lambda x:x**2, map(int, raw_input().split()[1:])))
print max(map(lambda x:x%m, map(sum, itertools.product(*ls))))