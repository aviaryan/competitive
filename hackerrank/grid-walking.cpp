#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll facts[301];

void initfact(){
	ll i,s=1; facts[0] = 1;
	for (i=1; i<=300; i++){
		s = m(s*i);
		facts[i] = s;
	}
}

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

ull combination(ll n, ll r){
	return m( facts[n] * m( PowMod(m(facts[r] * facts[n-r]), MODULO-2) ) );
}



int main(){
	int t, i, n, m, j, k;
	int sp[10], sizes[10];
	int ways[10][301][101];
	ios_base::sync_with_stdio(0);
	initfact();
	cin >> t;

	while (t--){
		cin >> n >> m;
		for (i=0; i<n; i++)
			cin >> sp[i];
		for (i=0; i<n; i++)
			cin >> sizes[i];

		for (j=0; j<=m; j++)
			for (i=0; i<n; i++)
				for (k=0; k<=sizes[i]; k++){
					if (k==0) // give k=0 more priority than j=0
						ways[i][j][k] = 0;
					else if (j==0)
						ways[i][j][k] = 1;
					else if (k == sizes[i])
						ways[i][j][k] = ways[i][j-1][k-1];
					else
						ways[i][j][k] = m( ways[i][j-1][k-1] + ways[i][j-1][k+1] );
				}

		ll ans[m+1], ansbk[m+1];
		for (i=0; i<=m; i++)
			ans[i] = ways[0][i][sp[0]];

		ll temp=0;
		for (i=1; i<n; i++){
			for (j=0; j<=m; j++){
				temp = 0;
				for (k=0; k<=j; k++)
					temp += m( m( ans[k] * ways[i][j-k][sp[i]] ) * combination(j,k) );
				ansbk[j] = m(temp);
			}
			for (j=0; j<=m; j++) ans[j] = ansbk[j];
		}
		cout << ans[m] << endl;
	}
	return 0;
}