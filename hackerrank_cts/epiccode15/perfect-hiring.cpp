#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	ll n, p, x, mx, mid, a;
	ios_base::sync_with_stdio(0);
	cin >> n >> p >> x;

	mx = 0;
	for (i=0; i<n; i++){
		cin >> a;
		if ( (a*p) > mx ){
			mid = i;
			mx = a*p;
		}
		p -= x;
	}

	cout << mid+1;

	return 0;
}