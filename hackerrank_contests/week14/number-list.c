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
	int t, k, j;
	scanf("%d", &t);
	ull ans,i,cp,n;

	while (t--){
		scanf("%llu %d", &n, &k);
		cp = 0;
		ans = 0;
		for (i=0; i<n; i++){
			scanf("%d", &j);
			if (j>k){
				// i-cp
				ans = ans + ((i-cp)*(i-cp+1)/2); // ans has no of subseqs who fail
				cp = i+1;
			}
		}
		ans = (n*(n+1)/2) - ans;
		ans = ans - ( (n-cp)*(n-cp+1)/2 ); // last ones that found no j>k
		printf("%llu\n", ans);
	}
	return 0;
}
// look at my code, my code is amazing