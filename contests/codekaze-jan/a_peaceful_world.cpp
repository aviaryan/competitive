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
	ll t, i, n, k;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	ll xs[n], ys[n], rad[n];

	for (i=0; i<n; i++){
		cin >> xs[i] >> ys[i];
		rad[i] = xs[i] * xs[i] + ys[i] * ys[i];
	}

	sort(rad, rad+n);

	// cout << sqrt(rad[k-1]) << endl;
	printf("%.6lf\n", sqrt(rad[k-1]));

	return 0;
}