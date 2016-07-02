#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll n,k,p,a;

	while (t--){
		cin >> n >> k;
		p = 0;
		for (i=0; i<n; i++){
			cin >> a;
			p += a;
			if (p % k != 0)
				p++;
		}
		cout << (ll) ceil( (double) p / (double) k ) << endl;
	}
	return 0;
}