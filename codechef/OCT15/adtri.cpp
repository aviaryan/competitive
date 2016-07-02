#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define LT 5000000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool ishyp[LT+1];

int main(){
	int t, i, j, k, x, n, ct=0, ct2=0, i2;
	s(t);
	int limit = ceil(sqrt(LT));
	
	fill_n(ishyp, LT+1, false);

	for (i=1; i<=limit; i++){
		i2 = i*i;
		for (j=i+1; j<=limit; j++){ // euclid's
			k = i2 + j*j;
			if (k > LT) break;
			if (ishyp[k]) continue;
			for (x=k; x<=LT; x+=k){
				ishyp[x] = true;
			}
		}
	}

	while (t--){
		s(n);
		printf("%s\n", ishyp[n] ? "YES" : "NO");
	}

	return 0;
}