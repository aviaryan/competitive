#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n;
	ll a, cur, me;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n;
		cur = 0; me=0;
		for (i=0; i<n; i++){
			cin >> a;
			if (a>cur)
				me += (a-cur);
			cur = a;
		}
		cout << me << endl;
	}
	return 0;
}