#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int k;
	scanf("%d", &k);

	int i, r, c;
	unsigned long long n,n2;
	for (i=0; i<k; i++){
		scanf("%llu", &n);
		c = 0;
		n2 = n;
		while (n>0){
			r = n%10;
			n = n/10;
			if (r!=0)
				if (n2%r == 0)
					c++;
		}
		printf("%d\n", c);
	}
}
