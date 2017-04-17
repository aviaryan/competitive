#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n, i, j;
	ll ib, jb;
	ios_base::sync_with_stdio(0);
	cin >> n;
	ll arr[n], max = 0, px, ct=0;

	for (i=0; i<n; i++) 
		cin >> arr[i];

	int n2 = 2*n - 2;
	for (j=1; j<n2; j++){
		ib = 0; jb = j;
		if (jb >= n){
			ib += (jb-n);
			jb = n-1;
		}
		px = 0;
		while (ib < jb){
			px += (arr[ib] * arr[jb]);
			//ct++;
			if (px > max) max = px;
			if (px < 0) px = 0;
			ib++; jb--;
		}
	}

	cout << max;
	// cout << ct;

	return 0;
}