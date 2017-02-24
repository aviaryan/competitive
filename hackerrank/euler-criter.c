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

ll PowMod(int bs, int n, int modx)
{ // base^n % modx
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % modx;
        a = a * a % modx;
        n >>= 1;
    }
    return ret;
}

int main(){
	int t, z, a, m;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &a, &m);
		if (a==0){
			z = 1; //as x could be m , then x^2 is always 0
		}
		else
			z = (int) PowMod(a, (m-1)/2, m);
		printf("%s\n", z==1 ? "YES" : "NO");
	}
	return 0;
}