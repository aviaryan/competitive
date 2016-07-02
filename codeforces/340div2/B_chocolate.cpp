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
	int t, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	ll last1 = -1;
	ll ans = 1;
	ll i;

	for (i = 0; i<n; i++){
		cin >> t;
		if (t == 1){
			if (last1 != -1)
				ans *= (i - last1);
			last1 = i;
		}
	}

	if (last1 == -1)
		ans = 0;
	cout << ans << endl;
	return 0;
}