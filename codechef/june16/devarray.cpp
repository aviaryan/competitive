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
	int t, i, k, n, q, mn = MODULO, mx = 0;
	s(n); s(q);
	for (i=0; i<n; i++){
		s(k);
		mn = min(k, mn);
		mx = max(k, mx);
	}
	for (i=0; i<q; i++){
		s(k);
		if (k>= mn && k<=mx){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}