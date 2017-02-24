#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<pii>::iterator vpiit;

vpii arr;
vpiit endarr;
ull ans=0;

void solve(vpiit z, ull carry){
	if (z==endarr){
		ans += carry;
		return;
	}
	int k = z->second, f = z->first;
	ull t=1;
	for ( ;k>=0; k--){
		solve(++z, carry*t);
		z--;
		t*=f;
	}
}

int main(){
	int t, z, i, ct, n;
	cin >> t;
	pii pr;

	while (t--){
		scanf("%d", &n);
		z = ceil(sqrt(n));
		arr.clear();
		if (n==1){
			cout << 1 << endl;
			continue;
		}

		ct=0;
		while (n%2 == 0) n=n/2, ct++;
		if (ct>0)
			arr.push_back( make_pair(2, ct) );

		for (i=3; i<=z; i=i+2){
			ct = 0;
			while (n%i == 0){
				n = n/i; ct++;
			}
			if (ct>0)
				arr.push_back( make_pair(i, ct) );
			if (n==1) break;
		}
		if (n>2) // prime num
			arr.push_back( make_pair(n, 1) );

		// print
		ans = 0;
		endarr = arr.end();
		solve(arr.begin(), 1);
		cout << ans << endl;
	}
	return 0;
}