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
	int t, i;
	ll n, m, s;
	s(t);

	while (t--){
		scanf("%lld %lld %lld", &n, &m, &s);
		m = m % n;
		m = (s-1) + (m-1);
		n = (n + m) % n;
		printf("%lld\n", n+1);
	}

	return 0;
}