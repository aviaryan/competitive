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
	int t, i, n;
	// /ios_base::sync_with_stdio(0);
	s(t);

	// preproc
	double ans[100001]; ans[0] = 0;

	for (i=1; i<=100000; i++)
		ans[i] = ans[i-1] + ( 1.0/(double)i );

	while (t--){
		s(n);
		printf("%.6lf\n", ans[n]);
	}

	return 0;
}