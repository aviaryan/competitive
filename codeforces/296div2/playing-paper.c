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
	ull a,b,ans=0,t;
	scanf("%I64d %I64d", &a, &b);

	while (a!=b){
		// assume a>b
		if (a%b == 0){
			ans += a/b;
			break;
		}
		else {
			ans = ans + (a/b);
			a -= b*(a/b);
			t = a;
			a = b;
			b = t;
		}
	}
	if (a==b)
		ans++;

	printf("%I64d\n", ans);
	return 0;
}