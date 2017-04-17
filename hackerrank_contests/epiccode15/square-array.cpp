#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n, q, i, x, y, op, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> q;

	// int sar[n+1]; sar[0] = 0;
	ll arr[n+1], p, ps;
	fill_n(arr, n+1, 0);

	// for (i=1; i<n; i++)
	// 	sar[i] = (i*(i+1)) + sar[i-1];

	for (i=0; i<q; i++){
		cin >> op >> x >> y;

		if (op == 1){
			p = 1; ps = 0;
			for (j = x; j<=y; j++){
				ps += (p*(p+1));
				arr[j] += ps;
				p++;
			}
			for (j=y+1; j<=n; j++)
				arr[j] += ps;
		} else {
			cout << m(arr[y] - arr[x-1]) << endl;
		}

	}
	return 0;
}