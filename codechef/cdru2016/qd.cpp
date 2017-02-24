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


void myprint(ll n, ll k){
	printf("(%lld,%lld)", n, k);
}


int main(){
	ll t, i, n, k;
	// ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		s(n);
		k = log(n);
		myprint(n, 1);
		myprint(m, n-1);
		for (i=2; i<=20; i++){
			
		}
	}

	return 0;
}