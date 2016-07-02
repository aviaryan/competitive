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
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;

	int arr[n+1], xors[n+1];
	xors[0] = 0;

	for (i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		xors[i] ^= xors[i-1];
	}

	

	return 0;
}