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

bool isMSbit(ull n){
	ull mask = 1<<31;
	return (n & mask) ? 1 : 0;
}

ull solve(ull digs, int a, int b){
	a <<= (31-digs);
	b <<= (31-digs);
	int c, d=0;
	ull ans=0;

	for (c=0; c<=digs; c++){
		if (isMSbit(a))
			ans += pow(2,digs-c);
		else
			if (isMSbit(b))
				break;
		a <<=1;
		b <<=1;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	ull a, b, s, lmt, ans;

	while (t--){
		scanf("%llu %llu", &a, &b);
		if (a==0){ // a = 0 = 0
			printf("0\n");
			continue;
		}

		s = (ull) ceil( log(a)/log(2) );
		lmt = pow(2,s);
		if ( lmt>=a && ((ull) pow(2,s+1)<=b) ) { // 2 or more 2 powers in range = 0 clean
			ans = 0;
		} else {
			s = log(b)/log(2);
			lmt = pow(2,s);
			if (lmt <= b && lmt>a){ // 2 pow is single but not a = 0
				ans = 0;
			} else if (lmt==a) { // 2 pow is start num
				ans = a;
			} else { // no 2 pow inside range FUCK
				ans = solve(s, a, b);
			}

		}
		printf("%llu\n", ans);
	}

	return 0;
}