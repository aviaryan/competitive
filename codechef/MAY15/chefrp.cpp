#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, j;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int suc = 0, sum, minn;

	while (t--){
		cin >> n;
		suc = 1; sum = 0; minn = 1000000;
		for (i=0; i<n; i++){
			cin >> j;
			sum += j;
			if (j<2) suc = 0;
			minn = min(minn, j);
		}
		if (!suc)
			cout << -1 << endl;
		else
			cout << sum - minn + 2 << endl;
	}
	return 0;
}