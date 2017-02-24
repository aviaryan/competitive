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
	int t, i, n, k, e, j;
	// ios_base::sync_with_stdio(0);
	// cin >> t;
	s(t);

	ll table[51][51];
	ll sum;
	ll ans;

	table[1][1] = 1;
	for (i=2; i<=50; i++){
		table[i][1] = 1;
		for (j=2; j<=i; j++){
			sum = 0;
			for (k=i-1; k>=(j-1); k--){
				sum = m(sum + table[k][j-1]);
			}
			table[i][j] = sum;
		}
	}

	ll lp, tfact, kc;
	while (t--){
		s(n);
		s(k);
		for (i=0; i<(2*n-2); i++) 
			s(e);
		ans = 0;
		for (i=1; i<=min(k, n); i++){
			tfact = 1;
			kc = k;
			for (lp=0; lp<i; lp++){
				tfact = m(tfact * kc);
				kc--;
			}
			ans = m(ans + m(m(table[n][i]) * tfact));
		}
		printf("%lld\n", ans);
	}

	return 0;
}