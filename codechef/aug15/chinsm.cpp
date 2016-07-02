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
	ll i, n, j;
	int t,k;
	
	scanf("%lld %d", &n, &k);
	ll total = (n * (n+1))/2;
	ll neg = 0;

	int q[100000];
	ll f=0;

	for (i=0; i<n; i++){
		s(t);

		if (t <= k){
			q[i] = t;
			continue;
		}

		for (j=i-1; j>=f; j--)
			if ( (q[j] % t) == k ){
				neg += ((j - f + 1) * (n-i));
				f = j+1;
				break;
			}

		q[i] = t;
	}

	printf("%lld", total - neg);
	return 0;
}

/*
2 mod
10 4 10 4
*/