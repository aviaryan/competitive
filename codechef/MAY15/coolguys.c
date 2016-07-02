#include "stdio.h"
#include "math.h"

#define s(a) scanf("%d", &a)
#define ll long long

// http://en.wikipedia.org/wiki/Divisor_summatory_function

ll gcd(ll a, ll b) {
   return (b==0) ? a : gcd(b, a%b);
}

void reduce_print(ll a, ll b){
	ll x = gcd(b, a);
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