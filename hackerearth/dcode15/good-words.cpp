#include "bits/stdc++.h"
#define MODULO 10000001
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll fact(ll n){
	ll i, s=1;
	for (i=2; i<=n; i++)
		s = md(s*i);
	return s;
}


int main(){
	ll t, i;
	//ios_base::sync_with_stdio(0);
	cin >> a >> b;
	int hcf = __gcd(a,b);
	

	return 0;
}