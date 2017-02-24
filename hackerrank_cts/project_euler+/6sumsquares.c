#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SZ 10000

int main() {
	int t,j,k;
	scanf("%d", &t);

	unsigned long long df=0, i, difs[SZ];
	for (i=1; i<=SZ; i++){
		df += i*i*(i-1); // i^3 - i^2
		difs[i-1] = df;
	}

	for (;t>0;t--){
		scanf("%d", &j);
		printf("%llu\n", difs[j-1]);
	}
}
