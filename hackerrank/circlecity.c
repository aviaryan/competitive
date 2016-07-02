#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t, s;
	scanf("%d", &t);
	unsigned long long r,min,i,j,realr;
	long long k;

	for (;t>0;t--){
		scanf("%llu %llu", &r, &k);
		min = sqrt(r/2);

		s = 1;
		realr = sqrt(r);
		if (realr*realr == r)
			k-=4; // the extremes
		if (k<0){
			printf("impossible\n");
			continue;
		}

		for (i=1; i<=min; i++){
			j = sqrt( r - i*i );
			if (i*i + j*j == r){
				k-=8;
				if (k<0){
					s = 0;
					break;
				}
			}
		}

		//printf("%lld", k);

		printf("%s\n", s==1 ? "possible" : "impossible");
	}   

    return 0;
}
