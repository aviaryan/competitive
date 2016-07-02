#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LIMIT 40

int main() {
	int t,n,i,j,k;
	unsigned long long s, ps;
	scanf("%d", &t);
	unsigned long long ans[LIMIT];

	s = 1;
	for (i=1; i<=LIMIT; i++){ // go through all numbers from 1 to LIMIT
		ans[i-1] = s;
		if (s%i == 0)
			continue;
		s *= i; // fast hand multiply by i
		for (j=2; j<=i; j++){
			if (i%j == 0) // if j is a factor of i
			{
				while (s%i == 0) // then trya removing to see if its OK
					s /= j;
				s *= j;
			}
		}
		ans[i-1] = s;
	}

	for (;t>0;t--){
		scanf("%d", &n);
		printf("%llu\n", ans[n-1]);
	}
}
