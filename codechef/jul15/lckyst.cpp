#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, a, fct, tct;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll ab, b;

	// 5^13 is just more 10^9
	// 7744
	while (t--){
		cin >> a;
		fct = 0; ab = a;
		while (ab%5 == 0){
			ab = ab/5;
			fct++;
		}
		if (fct == 0){
			cout << a << endl;
			continue;
		}
		tct = 0; ab = a;
		while (ab%2 == 0){
			ab = ab/2;
			tct++;
		}
		if (tct >= fct){
			cout << a << endl;
			continue;
		}

		b = pow(4, ceil( (fct-tct) / 2.0 ));
		cout << (ll) a * b << endl;
	}
	return 0;
}