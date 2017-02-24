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

ll gcd(ll a, ll b) {
   return (b==0) ? a : gcd(b, a%b);
}

int main(){
	int t, i;
	s(t);
	ll a, b, c, d, ans, k, diff, hcf;

	while (t--){
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		diff = abs(a-b);
		hcf = gcd(c, d);
		k = diff/hcf;
		ans = min( abs(k*hcf - diff), abs((k+1)*hcf - diff) );
		p(ans);
	}

	return 0;
}