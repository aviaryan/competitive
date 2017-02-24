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

ull Pow2Mod(ull n)
{
    ull ret = 1;
    ull a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	ull ans, n, rem, quot;
	ull t30 = (ull) pow(2,30);

	while (t--){
		scanf("%llu", &n);
		n++;
		ans = Pow2Mod(n);
		ans+=(4-2);
		printf("%llu\n", ans);
	}
	return 0;
}