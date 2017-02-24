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
	int t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;

	unsigned int arr[n];
	int modc[k];
	fill_n(modc, k, 0);

	for (i=0; i<n; i++){
		cin >> j;
		modc[ j % k ] ++;
	}

	int ans = (modc[0] > 0) ? 1 : 0;
	int lmt = (k%2 == 0) ? k/2 : (k/2) + 1;
	for (i=1; i < lmt; i++){
		ans += max(modc[i], modc[k-i]);
	}
	if (k % 2 == 0) // take left out middle
		ans += (modc[k/2] > 0) ? 1 : 0;

	cout << ans << endl;

	return 0;
}