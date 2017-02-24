#include "bits/stdc++.h"
#define MODULO 1000000007
#define BIG 1LL<<60
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%d", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, j;
	s(n);
	int p[n], a[n];
	ll h[n];
	ll en[n], mn;

	for (i=0; i<n; i++)
		scanf("%d", p+i);
	for (i=0; i<n; i++)
		scanf("%d", a+i);
	for (i=0; i<n; i++)
		scanf("%lld", h+i);

	en[n-1] = a[n-1];
	for (i=n-2; i>=0; i--){
		en[i] = a[i];
		mn = BIG;
		for (j=i+1; j<n; j++){
			if (p[j] > p[i])
				mn = min( (h[j]-h[i])*(h[j]-h[i]) + en[j] , mn );
		}
		en[i] += mn;
	}

	printf("%lld", en[0]);

	return 0;
}