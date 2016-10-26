#include "bits/stdc++.h"
#define MODULO 13313
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;
#define LT 200001

typedef unsigned long long ull;
typedef long long ll;

ll facts[LT];
int counts[LT];
ll globAns = 0;

void initfact(){
	ll i, s=1; facts[0] = 1;
	for (i=1; i<LT; i++){
		s = m(s*i);
		facts[i] = s;
	}
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

void solve(int place, int rem, ll ans){
	if (place >= LT)
		return;
	if (rem < 0)
		return;
	if (rem == 0){
		globAns = m(globAns + ans);
		return;
	}
	int i;
	int sz = counts[place];
	solve(place+1, rem, ans);

	for (i=1; i<=sz; i++){
		solve(place+1, rem-(place*i), m(ans * combination(sz, i)));
	}
}

int main(){
	int t, i, n, k;
	s(n); s(k);
	initfact();

	int nums[LT];
	fill_n(nums, LT, 0);
	for (i=0; i<n; i++){
		s(t);
		nums[t]++;
	}

	fill_n(counts, LT, 0);
	for (i=0; i<LT; i++){
		counts[nums[i]]++;
	}

	globAns = 0;
	solve(1, k, 1);
	printf("%lld\n", globAns);

	return 0;
}