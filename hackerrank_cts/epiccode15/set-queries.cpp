#include "bits/stdc++.h"
#define MODULO 1000000009
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	ll t, i, n, s, m, sz, j, op, l, r, a;
	ios_base::sync_with_stdio(0);
	cin >> n >> s >> m;

	ll * sad[s], * ptr;

	for (i=0; i<s; i++){
		cin >> sz;
		ll * arr = (ll *) malloc( (sz+1) * sizeof(ll) );
		arr[0] = sz;
		for (j=1; j<=sz; j++) cin >> arr[j];
		sad[i] = arr;
	}

	ll arr[n+1];
	fill_n(arr, n+1, 0);
	ll sum;

	// TESTING A THEORY
	map <ll, ll> sr;
	//ll upd=0;

	while (m--){

		cin >> op;
		if (op == 1){
			cin >> a >> t;
			ptr = sad[a-1];
			sz = ptr[0];
			for (j=1; j<=sz; j++)
				arr[ ptr[j] ] += t;
		} else if (op == 2){
			cin >> a;
			if (sr.find(a-1) != sr.end()){
				cout << sr[a-1] << endl;
			} else {
				sum = 0;
				ptr = sad[a-1]; sz = ptr[0];
				for (j=1; j<=sz; j++) sum = sum + arr[ ptr[j] ];
				cout << m(sum) << endl;
				sr[a-1] = m(sum);
			}
		} else if (op == 3){
			cin >> l >> r >> t;
			for (j=l; j<=r; j++) arr[j] += t;
		} else {
			cin >> l >> r;
			sum = 0;
			for (j=l; j<=r; j++) sum += arr[j];
			cout << m(sum) << endl;
		}

		if (op == 1 || op == 3){
			sr.clear();
		}

	}

	return 0;
}