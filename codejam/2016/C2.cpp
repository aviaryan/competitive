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

// for 32

int main(){
	int t, i, n, j, ct, k, i2, k2, lc, jk;
	scanf("%d", &t);

	for (lc=1; lc<=t; lc++){
		scanf("%d %d", &n, &jk);
		ct = 0;

		printf("Case #%d:\n", lc);

		for (i=3; i<=(n-2-2-2-1); i++){
			for (j=i+2; j <= (n-2-2-1); j++){
				for (k=j+2; k <= (n-2-1); k++){
					// print the trio
					printf("11");
					for (i2=3; i2<=(n-2); i2++){
						if (i2 == i || i2 == j || i2 == k){
							printf("11");
							i2++;
						} else {
							printf("0");
						}
					}
					printf("11 ");
					// done printing now divisors
					// print divs
					for (k2=2; k2<=10; k2++)
						printf("%d ", k2+1);
					printf("\n");
					ct++;
					if (ct == jk) break;
				}
				if (ct == jk) break;
			}
			if (ct == jk) break;
		}

	}

	return 0;
}