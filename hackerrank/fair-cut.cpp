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

ll arr[3000+1];
ll n, k;

int main(){
	ll t, i, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	arr[0] = 0;
	for (i=1; i<=n; i++)
		cin >> arr[i];
	sort(arr, arr+n+1);
	if (k*2 > n) k = n-k;
	// solve
	ll start;
	if (n % 2 == 0){
		if (k % 2 == 0){
			start = n/2 - 1 - (k/2 - 1)*2;
		} else {
			start = n/2 - (k/2) * 2;
		}
	} else {
		if (k % 2 == 0){
			start = n/2 - (k/2 - 1)*2;
		} else {
			start = n/2 + 1 - (k/2) * 2;
		}
	}

	ll kser[k], remser[n-k], ksc = 0, remsc = 0;
	for (i=1; i<start; i++) remser[remsc++] = arr[i];
	for (i=start; i<=(start + 2*(k-1)); i+=2) kser[ksc++] = arr[i];
	for (i=start+1; i<(start + 2*(k-1)); i+=2) remser[remsc++] = arr[i];
	for (i=start + 2*(k-1) + 1; i<=n; i++) remser[remsc++] = arr[i];

	ll ans = 0;
	for (i=0; i<k; i++)
		for (j=0; j<(n-k); j++)
			ans += abs(kser[i] - remser[j]);
	cout << ans << endl;

	return 0;
}