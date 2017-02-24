#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	unsigned long long i;
	unsigned long long a,b;
	unsigned long long k, n, m, t2, s=0;

	scanf("%llu %llu", &n, &m);
	// unsigned long long arr[n]; fuck off - no need of an array to hold - REALLY

	for (i=0; i<m; i++){
		scanf("%llu %llu %llu", &a, &b, &k);
		/*for (t2=a-1; t2<b; t2++){
			s += k;
		}*/
		s += (k*(b-a+1));
	}

	printf("%llu", s/n);

    return 0;
}
