#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, a;
	ll j, k;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;

	set <ll> rec;

	for (i=0; i<n; i++){
		cin >> j;
		rec.insert(j);
		rec.insert(j+k);
	}

	cout << 2*n - rec.size();

	return 0;
}