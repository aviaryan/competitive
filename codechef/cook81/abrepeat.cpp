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
	int t;
	ll i;
	ios_base::sync_with_stdio(0);
	s(t);
	char str[100000 + 1];
	ll prev_a, k, n;
	ll tsum;
	ll ac, bc;
	ll ans, first, full;

	while (t--){
		scanf("%lld", &n);
		scanf("%lld", &k);
		scanf("%s", str);
		prev_a = 0; ac=0; bc=0; tsum = 0;

		for (i=0; i<n; i++){
			if (str[i] == 'a'){
				ac++;
			}
			if (str[i] == 'b'){
				tsum += ac;
				bc++;
			}
		}
		// printf("%lld %lld %lld\n", ac, bc, tsum);
		first = tsum;
		ans = tsum + (ac * (bc * (k-1LL))); // first seg a before b
		full = ans;

		// printf("<< %lld >>\n", ans);
		ans += (k-1) * tsum;
		if (k > 1){
			ans += (ac * bc) * ((k-1) * (k-2) / 2LL);
		}
		// for (i=2; i<=k; i++){
		// 	ans += (ac * (bc * (k - i)));
		// }

		printf("%lld\n", ans);
	}

	return 0;
}