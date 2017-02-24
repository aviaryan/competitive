#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

int main(){
	int t;
	scanf("%d", &t);
	ull n,s, d, k;

	while (t--){
		scanf("%llu %llu", &n, &s);
		d = n*(n+1)/2;
		if (n*(n+1)==s*2)
			printf("0\n");
		else
		{
			// if n=6, then 20 is 1 , 15 is 2 , 11 is 3, 8 is 4, 6 is 5
			d = d-s;
			n--;
			/*
				d = k/2 * (2*n + (1-k)) // AP form
				k = 2*n+1 - sqrt( 2(n+1) ^ 2 - 8d ) / 2 // quadratic
			*/
			n = 2*n + 1;
			k = (ull) ceil( (n - sqrt(n*n - 8*d)) / 2 );
			printf("%llu\n", k);
		}

	}
	return 0;
}