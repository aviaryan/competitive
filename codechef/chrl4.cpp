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
	int t, i, j, n, k;
	//ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &k);
	ll arr[n];

	for (i=0; i<n; i++) scanf("%lld", &arr[i]);

	ll mins[n], cmin;
	int minid, localn;

	mins[n-1] = arr[n-1]; // last one

	if (k >= (n-1)){ // go case
		printf("%lld\n", m(arr[0] * arr[n-1]));
		return 0;
	}

	for (i=n-k-1; i<(n-1); i++){
		mins[i] = m(arr[i] * arr[n-1]);
	}

	for (i=n-k-2; i>=0; i--){
		minid = i+1;
		cmin = mins[minid];
		localn = i+k+1;
		for (j=i+2; j<localn; j++){
			if (mins[j] < cmin){
				cmin = mins[j];
				minid = j;
			}
		}
		mins[i] = m(arr[i] * cmin);
	}

	printf("%lld", mins[0]);

	return 0;
}