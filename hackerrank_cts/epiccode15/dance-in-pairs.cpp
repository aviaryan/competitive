#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n, i, k;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int boy[n], girl[n];

	for (i=0; i<n; i++) cin >> boy[i];
	for (i=0; i<n; i++) cin >> girl[i];

	sort(boy, boy+n); sort(girl, girl+n);
	
	int gp = 0, ans=0;
	for (i=0; i<n; i++){
		if (gp == n)
			break;
		if ( abs( boy[i] - girl[gp] ) <= k ){
			gp++; ans++;
		} else if (boy[i] > girl[gp]) {
			i--; // keep boy intact
			gp++;
		}
	}

	cout << ans;
	return 0;
}