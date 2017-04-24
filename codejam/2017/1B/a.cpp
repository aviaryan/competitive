#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%lf", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, tf;
	ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	double d, n, k[1001], s[1001], maxt=0, ct;

	for (tf=1; tf<=t; tf++){
		s(d); s(n);
		maxt = 0;
		for (i=0; i<n; i++){
			s(k[i]); s(s[i]);
			ct = (d - k[i]) / s[i];
			maxt = max(ct, maxt);
		}
		printf("Case #%d: %.7lf\n", tf, (d/maxt));
	}

	return 0;
}
