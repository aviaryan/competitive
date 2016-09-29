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
	int t, i, n, m;
	// ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &m);
	int arr[m];

	for (i=0; i<m; i++) 
		scanf("%d", &arr[i]);

	sort(arr, arr+m);

	int maxd = arr[0];

	for (i=0; i<(m-1); i++){
		maxd = max(maxd, (arr[i+1] - arr[i])/2);
	}

	maxd = max(maxd, n-1 - arr[m-1]);
	
	printf("%d", maxd);

	return 0;
}