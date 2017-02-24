#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, lc;
	scanf("%d", &t);
	ull k, c, s, j, cp, i;

	for (lc=1; lc<=t; lc++){
		scanf("%lld %lld %lld", &k, &c, &s);
		printf("Case #%d: ", lc);
		if (k == 1){
			printf("1\n");
			continue;
		}
		if (c==1){
			if (s < k){
				printf("IMPOSSIBLE\n");
			} else {
				for (i=1; i<=k; i++)
					printf("%d ", i);
				printf("\n");
			}
			continue;
		}

		if (s < ((k/2) + (k%2))){ // last check for impossible
			printf("IMPOSSIBLE\n");
			continue;
		}

		for (i=0; i<(k/2); i++){
			cp = i*2 + 1;
			for (j=2; j<=c; j++){
				cp = (cp-1)*k + 2*(i+1);
			}
			printf("%lld ", cp);
		}
		if (k%2 == 1){
			printf("%lld ", (ll) pow(k,c));
		}
		printf("\n");
	}

	return 0;
}