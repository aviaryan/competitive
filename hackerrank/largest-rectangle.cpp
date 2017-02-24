#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


void solve(ll * arr, int sz, int d, ll * xar){
	ll init, cond, incr, i;
	if (d==1){
		init = 0; cond = sz; incr = 1;
	} else {
		init = sz-1; cond = -1; incr = -1;
	}

	ll n, rh, ri;
	stack <ll> hts;
	stack <ll> inds;
	hts.push(0); // just for 

	for (i = init; i != cond; i=i+incr){
		n = arr[i];
		while (hts.top() > n){
			xar[inds.top()] = abs(i-inds.top());
			hts.pop(); inds.pop();
		}
		hts.push(n); inds.push(i);
	}

	if (d==0) sz = -1;

	while (hts.top() != 0){
		xar[inds.top()] = abs(sz-inds.top());
		hts.pop(); inds.pop();
	}
}

int main(){
	ll t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll area = 0;
	ll arr[t];
	ll forw[t];
	ll back[t];

	for (i=0; i<t; i++)
		cin >> arr[i];

	solve(arr, t, 1, forw);
	solve(arr, t, 0, back);

	for (i=0; i<t; i++)
		area = max(area, arr[i] * (forw[i] + back[i] - 1));

	cout << area;

	return 0;
}