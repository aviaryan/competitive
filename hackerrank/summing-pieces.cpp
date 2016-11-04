#include "bits/stdc++.h"
#define MODULO 1000000007LL
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll PowMod(ll bs, ll n){
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
	ll t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	ll arr[n+1];
	for (i=1; i<=n; i++)
		cin >> arr[i];
	if (n == 1){
		cout << arr[1] << endl;
		return 0;
	}
	// thanks to gurupad for pattern
	ll ans = 0;
	ll p = m(PowMod(2, n) - 1LL + MODULO);
	ans = m(ans + m((arr[1] + arr[n]) * p));
	ll y = n-2, yd = 0;
	for (i=2; i<=(n+1)/2; i++){
		p = m(p + PowMod(2, y--) - PowMod(2, yd++) + MODULO);
		if (n%2 == 1 && i == (n+1)/2)
			ans = m(ans + m(arr[i] * p));
		else
			ans = m(ans + m((arr[i] + arr[n-i+1]) * p));
	}
	cout << ans << endl;

	return 0;
}