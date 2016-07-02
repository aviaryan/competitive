#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int arr[100000], n;
ll sols[100000];
ll sums[100000];

ll solve(int i){
	if (i >= n)
		return 0;
	if (sols[i] != -1)
		return sols[i];

	if (solve(i+1) < solve(i+2)){
		if (solve(i+1) < solve(i+3))
			return sols[i] = arr[i] + sums[i+1]-solve(i+1);
		else // 3 is small or equal
			return sols[i] = arr[i]+arr[i+1]+arr[i+2] + sums[i+3]-solve(i+3);
	} else {
		if (solve(i+2) < solve(i+3))
			return sols[i] = arr[i]+arr[i+1] + sums[i+2]-solve(i+2);
		else // 3 is small or eq
			return sols[i] = arr[i]+arr[i+1]+arr[i+2] + sums[i+3]-solve(i+3);
	}
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll ans;

	while (t--){
		cin >> n;
		for (i=0; i<n; i++)
			cin >> arr[i];

		sums[n-1] = arr[n-1];
		for (i=n-2; i>=0; i--)
			sums[i] = arr[i]+sums[i+1];

		if (n<4){
			cout << sums[0] << endl;
			continue;
		}

		fill_n(sols, n, -1);
		sols[n-1] = arr[n-1];
		sols[n-2] = arr[n-2] + sols[n-1];
		sols[n-3] = arr[n-3] + sols[n-2];

		ans = solve(0);
		cout << ans << endl;
	}
	return 0;
}