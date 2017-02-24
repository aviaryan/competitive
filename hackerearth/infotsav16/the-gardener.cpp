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
	int t, i, p, n, k, d, f;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> p >> n >> k;
		int flowers[n];
		int dists[n];
		for (i=0; i<n; i++){
			cin >> d >> f;
			flowers[i] = f;
			dists[i] = d;
		}
		while (true){
			// front
			for (i=0; )
		}
	}

	return 0;
}