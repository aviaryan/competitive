#include "bits/stdc++.h"
#define MODULO 1000003
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;

ll initv = 1000002;

ll PowMod(int bs, int n)
{ // base^n % modULO
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}
 
ll factorial(ll n, ll l){
	ll f=1;
	n %= MODULO;
	l %= MODULO;
	
	for (;n>l;n--)
		f = (f*n) % MODULO;
	return f;
}

ll solvelarge(ll num, ll den, ll den2){
	ll k2 = den2/MODULO;
	ll k11 = ceil( (den+1)/(double) MODULO);
	ll k12 = num/MODULO;
	ll k1 = k12-k11+1;

	if (k1 > k2) // the opposite not possible
		return 0;
	else {
		ll ans2 = factorial(den2-(k2*MODULO), 1);
		ans2 = (ans2 * PowMod(initv, k2)) % MODULO;
		ans2 = (ans2 * factorial(k2, 1)) % MODULO;

		ll ans;
		if (k1>0) {
			ans = factorial(k11*MODULO -1, den);
			ans = (ans * factorial(num, k12*MODULO)) % MODULO;
			ans = (ans * PowMod(initv, k12-k11)) % MODULO;
			ans = (ans * factorial(k12, k11-1)) % MODULO;
		} else 
			ans = factorial(num, den);

		return (ans * PowMod(ans2, MODULO-2)) % MODULO;
	}
}

int main(){
	int t;
	ll n,l,r,k;
	ll ans, ans2;
	ll temp, num, den, den2;
	cin >> t;
 
	while (t--){
		scanf("%lld %lld %lld", &n, &l, &r);
		k = r-l+1;
		n++; k++;
		num = k+(n-2); den = n-1;
 
		if ( (num-den) > den ){
			temp = den;
			den = num-den;
			den2 = temp;
		} else
			den2 = num-den;

		ans = solvelarge(num, den, den2);

		if (ans == 0)
			ans = MODULO-1;
		else
			ans--;
		printf("%lld\n", ans);
	}
 
	return 0;
} 