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
	int t, i, j, k, n;
	//ios_base::sync_with_stdio(0);
	s(t);
	int arrx[500*500 + 1], arry[500*500 + 1], steps;

	while (t--){
		s(n);
		for (i=0; i<n; i++)
			for (j=0; j<n; j++){
				scanf("%d", &k);
				arrx[k] = i;
				arry[k] = j;
			}

		n *= n;
		steps = 0;
		for (i=2; i<=n; i++)
			steps += abs( arrx[i] - arrx[i-1] ) + abs( arry[i] - arry[i-1] );
		p(steps);
	}

	return 0;
}