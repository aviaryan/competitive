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

// all positive digit nums
// from right ... n/1 % 5 , n/5 % 5, n/25 % 5, n/125 % 5

int main(){
	int t, i;
	ll n, wt, cycle, fivef, tenf, ans;
	s(t);
	
	while (t--){
		sl(n);
		fivef = 1;
		tenf = 1;
		ans = 0;
		while (true){
			wt = (n-1)/fivef;
			if (wt==0) break;
			cycle = wt % 5;
			ans += (tenf * (2*cycle));
			tenf *= 10;
			fivef *= 5;
		}
		p(ans);
	}
	return 0;
}