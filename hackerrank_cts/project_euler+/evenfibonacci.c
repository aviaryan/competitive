#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);

	unsigned long long n,c,b,s;
	for (;t>0;t--){
		scanf("%llu", &n);
		c = 2, b = 1, s = 0;
		do {
			if (c%2==0)
				s += c;
			c = c+b;
			b = c-b;
		} while (n>=c);
		printf("%llu\n", s);
	}
}
