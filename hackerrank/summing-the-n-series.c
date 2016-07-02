#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MOD9 1000000007

int main(){
	int t;
	scanf("%d", &t);
	ull n;

	while (t--){
		scanf("%llu", &n);
		printf("%llu\n", ((n%MOD9) * (n%MOD9))%MOD9 );
	}
	return 0;
}