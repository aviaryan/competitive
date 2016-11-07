#include "bits/stdc++.h"
#define MODULO 998244353LL
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define sig(a) ((a>0) ? 1 : ((a<0) ? -1 : 0))
#define LOOPT 80000000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	ll t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	ll a[n], b[n];
	for (i=0; i<n; i++)
		cin >> a[i];
	for (i=0; i<n; i++)
		cin >> b[i];

	ll lt = n, prev, diff, ansk0 = -1LL;
	for (i=0; i<lt; i++){
		prev = m(a[0] - b[i] + MODULO);
		for (j=1; j<n; j++)
			if ( m(a[j] - b[(i+j) % n] + MODULO) != prev )
				break;
		if (j == n){
			ansk0 = i; break;
		}
		// deg 1
		// n=1 closed above
		prev = m(a[0] - b[i] + MODULO);
		if (k > 0){
			diff = m( m(a[1] - b[(i+1) % n] + MODULO) - prev + MODULO );
			prev = m(a[1] - b[(i+1) % n] + MODULO);
			for (j=2; j<n; j++){
				if (m( m(a[j] - b[(i+j) % n] + MODULO) - prev + MODULO ) != diff)
					break;
				prev = m(a[j] - b[(i+j) % n] + MODULO);
			}
			if (j == n){
				ansk0 = i; break;
			}
		}
	}

	// see graph
	ll deg, ansk1 = -1LL, cur, cdiff;
	int lc = 0;
	for (i=0; i<lt; i++){
		if (lc > LOOPT) break;
		prev = m(a[0] - b[i] + MODULO);
		diff = m(a[1] - b[(i+1) % n] + MODULO) - prev;
		prev = m(a[1] - b[(i+1) % n] + MODULO);
		deg = 0;
		if (diff != 0)
			deg++;
		if (deg > k) continue;
		for (j=2; j<n; j++){
			cur = m(a[j] - b[(i+j) % n] + MODULO);
			cdiff = cur - prev;
			if (sig(diff) == sig(cdiff))
				deg += 0;
			else
				deg += 1;
			if (deg > k) 
				break;
			prev = cur; diff = cdiff;
			lc++;
		}
		if (j == n){
			ansk1 = i;
			break;
		}
	}

	ll ans;
	if (ansk0 == -1)
		ans = ansk1;
	else if (ansk1 == -1)
		ans = ansk0;
	else
		ans = min(ansk0, ansk1);
	cout << ans << endl;

	return 0;
}