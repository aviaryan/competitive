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
	ll maxcont, maxnoncont, maxsofar, maxe, k, n, i;
	scanf("%lld", &n);
	maxcont = 0, maxnoncont = 0, maxsofar=0, maxe=0;
	for (i=0; i<n; i++){
		scanf("%lld", &k);
		if (k>maxe)
			maxe = k;
		if (k>0)
			maxnoncont += k;
		maxsofar += k;
		//printf("%lld %lld \n", k, maxsofar);
		if (maxcont < maxsofar)
			maxcont = maxsofar;
		if (maxsofar < 0 || k == 0)
			maxsofar = 0;
	}

	if (maxnoncont == 0)
		maxnoncont = maxe;
	if (maxcont == 0)
		maxcont = maxe;

	printf("%lld\n", maxcont);

	return 0;
}