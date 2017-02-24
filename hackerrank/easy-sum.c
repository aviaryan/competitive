#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t;
	scanf("%d", &t);
	ull n,m,ans,qut;

	while (t--){
		scanf("%llu %llu", &n, &m);
		qut = n/m;
		ans = (((m-1)*m)/2 * qut);
		qut = n%m;
		ans += qut*(qut+1)/2;
		printf("%llu\n", ans);
	}
	return 0;
}