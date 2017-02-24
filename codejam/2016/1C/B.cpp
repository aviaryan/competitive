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

// root of error - I thought 2^32 > 10^18 should be 2^64
ll nearest2power(ull n){
	ll i, x;
	for (i=0; i<=32; i++){
		x = pow(2LL, i);
		if (x > n) return i-1;
	}
	return 32;
}

int main(){
	int t, i, i2, j, b;
	//ios_base::sync_with_stdio(0);
	//cin >> t;
	scanf("%d", &t);
	bool mx[50][50];
	ull sum;
	ll cl, m, md;

	for (j=1; j<=t; j++){
		scanf("%d %lld", &b, &m);
		sum = 0;
		for (i=0; i<b; i++) 
			for(i2 = 0; i2<b; i2++) 
				mx[i][i2] = false;
		// false them all ^^
		for (i=1; i<b; i++){
			if (i==1){
				mx[0][b-1] = true;
				m--;
			} else if (i==2){
				mx[0][1] = true;
				mx[1][b-1] = true;
				m--;
			} else {
				//printf("%d\n", i);
				cl = (ll) pow(2ULL, (ull) i-2);
				//if (cl < 0) printf("cl problem");
				if (m >= cl){ // m more than limit
					mx[i-1][b-1] = true;
					for (i2=0; i2<(i-1); i2++){
						mx[i2][i-1] = true;
					}
					m -= cl;
				} else {
					mx[i-1][b-1] = true;
					// m less than limit be smart on what bridges to make
					while (m > 0){
						printf("hi %lld", m);
						md = nearest2power(m);
						if (md < 1LL){
							if (mx[0][i-1] == false) 
								mx[0][i-1] = true;
							else
								mx[1][i-1] = true;
						} else {
							printf("%lld", md);
							mx[md+1][i-1] = true;
						}
						//printf("md");
						m -= pow(2LL, (ll) md);
						if (pow(2LL, (ll) md) < 0) printf("another problem");
					}
				}
			}

			//printf("hi");
			if (m==0) break;
		}

		// check for results
		if (m != 0)
			printf("Case #%d: IMPOSSIBLE\n", j);
		else {
			printf("Case #%d: POSSIBLE\n", j);
			for (i=0; i<b; i++){
				for (i2=0; i2<b; i2++){
					printf("%d", (mx[i][i2]==true) ? 1 : 0);
				}
				printf("\n");
			}
		}

	}

	return 0;
}