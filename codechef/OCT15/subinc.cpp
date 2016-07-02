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
	int t, j, pj;
	ll ans, i, st, n;
	s(t);

	while (t--){
		scanf("%lld", &n);
		pj = 0;
		st = 0;
		ans = 0;
		for (i=0; i<n; i++){
			scanf("%d", &j);
			if (j < pj){
				ans += ( ((i-st) * (i-st+1)) / 2 );
				st = i;
			}
			pj = j;
		}
		ans += (((n-st) * (n-st+1)) / 2);
		printf("%lld\n", ans);
	}

	return 0;
}