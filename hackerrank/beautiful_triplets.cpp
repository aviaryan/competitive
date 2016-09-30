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
	int t, i, n, d, j;
	s(n);
	s(d);
	bool done[n];
	fill_n(done, n, false);
	int arr[n];

	for (i=0; i<n; i++) 
		s(arr[i]);

	int lc;
	int ans = 0;
	for (i=0; i<n; i++){
		if (done[i])
			continue;
		done[i] = true;
		lc = 1;
		for (j=i+1; j<n; j++){
			if ( (arr[j] - arr[i]) % d == 0 ){
				if ( (arr[j] - arr[i]) != lc*d ) // not in increments of d
					break;
				lc++;
				done[j] = true;
			}
		}
		if (lc > 2)
			ans += (lc-2);
	}

	p(ans);

	return 0;
}