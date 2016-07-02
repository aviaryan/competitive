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

// http://en.wikipedia.org/wiki/Divisor_summatory_function
void reduce_print(ll a, ll b){
	ll x = __gcd(a, b);
	printf("%lld/%lld\n", a/x, b/x);
}

int main(){
	int t, i, k, n, u;
	ll sum;
	s(t);

	while (t--){
		s(n);
		u = sqrt(n);
		sum = 0;
		for (i=1; i<=u; i++)
			sum += (n / i);
		sum = sum*2 - (ll) u*u;
		reduce_print(sum, (ll) n * (ll) n);
	}

	return 0;
}