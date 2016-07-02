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

#define LT 1e18


int main(){
	int t;
	//ios_base::sync_with_stdio(0);
	ll a, n, d, i;
	s(t);

	map <ll, ll> rec;

	// pre
	a = 1;
	rec[1] = 1;
	for (i=2; i<=64; i++){
		if (i%2 == 0)
			a *= 2;
		else {
			a /= (i/2 + 1);
			a *= i;
		}
		rec[a] = i;
		//printf("%lld %lld\n", i, a);
	}

	while (t--){
		sl(n);
		d = rec.lower_bound(n)->second;
		printf("%lld\n", d);
	}

	return 0;
}