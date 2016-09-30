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


ll xor_series(ll n){
	if (n % 2 == 1) {
	    return (n % 4 == 1) ? 1 : 0;
	} else {
		return (n % 4 == 0) ? n : n + 1;
	}
}

// http://math.stackexchange.com/questions/1558404/finding-xor-of-all-even-numbers-from-n-to-m
ll xor_even_series(ll n){
	if (n % 2 == 1) 
		n--;

	if (n % 8 == 0){
	    return n;
	} else if (n % 8 == 2){
		return 2;
	} else if (n % 8 == 4){
		return n+2;
	} else if (n % 8 == 6){
		return 0;
	}
}


int main(){
	int t, i, q;
	ll l, r;
	ll ans;
	s(q);

	while (q--){
		scanf("%lld %lld", &l, &r);
		ans = 0;
		if (l%2 == 0){ // consume first even; no pairing
			ans = xor_series(l);
			l++;
		}
		if (l == r){
			ans ^= xor_series(l);
		} else if (r > l){
			if ((r-l+1) % 2 == 0){
				ans = ans ^ (xor_even_series(r) ^ xor_even_series(l));
			} else {
				ans = ans ^ (xor_even_series(r-1) ^ xor_even_series(l)) ^ xor_series(r);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}