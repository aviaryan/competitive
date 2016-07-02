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

/*
For nth bit series
nums = pow(2,n-1)
total ones = nums * 0.5 * n + 0.5
*/

int countone(ull n){
    int count = 0;
    while (n > 0){
        count++;
        n = n & (n-1);
    }
    return count;
}

ull solve_intmd(a, b){

}

ull solve(a, b){
	ull ans=0;

	if (a==b)
		return countone(a);

	int z = (int) ceil( log(a)/log(2) );
	int z2 = log(b)/log(2);

	if (z == z2){

	} else {
		for (i=z; i<z2; i++)
			ans += pow(2,i) * ( 0.5 * (i+1) );
	}
	return solve(a, pow(2,z)) + ans + solve( pow(2,z2), b );
}

int main(){
	int t;
	scanf("%d", &t);
	ull ans;

	while (t--){
		scanf("%d %d", &a, &b);
		if (a<0 && b<0){
			ans = solve( -(a+1), -(b+1) );
			// more
		} else if (a<0 && b>0){
			ans = solve(1, -(a+1));
			// more
			ans += solve(1,b);
		} else {
			ans = solve(a,b);
		}

		printf("%llu\n", ans);
	}
	return 0;
}