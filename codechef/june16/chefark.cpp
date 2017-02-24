#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll facts[100000+1];

void initfacts(){
	ll i;
	facts[0] = 1; facts[1] = 1;
	for (i=2; i<=100000; i++)
		facts[i] = m(i*facts[i-1]);
}

ll PowMod(int bs, int n){
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

ll combination(ll n, ll r){
	return m( facts[n] * m( PowMod(m(facts[r] * facts[n-r]), MODULO-2) ) );
}


int main(){
	int t, i, n, k, j, minn, zc, sp;
	ll ans;
	initfacts();
	s(t);

	while (t--){
		scanf("%d %d", &n, &k);
		zc = 0;
		for (i=0; i<n; i++){
			s(j);
			if (j==0) zc++;
		}
		n -= zc;
		minn = min(n, k);
		ans = 0;
		if (zc > 0 || k%2==0) ans++;
		if (zc > 0)
			sp = 1;
		else
			sp = (k%2==0) ? 2 : 1;
		for (i=sp; i<=minn; i+=(zc > 0) ? 1 : 2){
			ans = m(ans + combination(n,i));
		}
		p(ans);
	}

	return 0;
}
