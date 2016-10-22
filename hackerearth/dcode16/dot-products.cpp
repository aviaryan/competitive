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


int main(){
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	vector <ll> u, v;

	for (i=0; i<n; i++){
		cin >> t;
		u.push_back(t);
	}

	for (i=0; i<n; i++){
		cin >> t;
		v.push_back(t);
	}

	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll min = 0;
	for (i=0; i<n; i++){
		min += u[i] * v[i];
	}

	printf("%lld\n", min);

	return 0;
}