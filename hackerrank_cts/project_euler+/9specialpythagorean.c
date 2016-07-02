#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long maxtripletprod(long long i){
	long long a,b,c;
	long long maxp = -1;
	for (a=2; a<(i/3); a++){ // a the least term is less than n/3
		for (b=(a+1); b<(i/2); b++){ // b should be less than n/2
			c = i-a-b;
			if ( a*a + b*b == c*c ){
				if ( a*b*c > maxp )
					maxp = a*b*c;
			}
		}
	}
	return maxp;
}


int main() {
	long long t;
	scanf("%lld", &t);
	long long a;
	long long maxps[3000] = {0};

	for (;t>0;t--){
		scanf("%lld", &a);
		if (maxps[a-1] == 0)
			maxps[a-1] = maxtripletprod(a);
		printf("%lld\n", maxps[a-1]);
	}
}
