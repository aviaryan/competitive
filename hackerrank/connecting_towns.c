#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);

	int i,k,j;
	unsigned long long n,f,r;
	for (i=0; i<t; i++){
		f = 1;
		r = 1;
		scanf("%d", &k);
		for (j=0; j<k-1; j++){
			scanf("%llu", &n);
			f = n*f;
			f = f%1234567;
		}
		printf("%llu\n", f);
	}

}