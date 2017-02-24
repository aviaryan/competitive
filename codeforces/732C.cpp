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
	ll t, i, b, d, s;
	ios_base::sync_with_stdio(0);
	cin >> b >> d >> s;
	if (b > max(d, s))
		cout << max(b-d-1 + b-s-1, 0LL) << endl;
	else if (d > max(b, s))
		cout << max(d-b-1 + d-s-1, 0LL) << endl;
	else if (s > max(d, b))
		cout << max(s-b-1 + s-d-1, 0LL) << endl;
	else if (b == d) // both are max and all equi
		cout << max(b-s-1, 0LL) << endl;
	else if (s == d)
		cout << max(s-b-1, 0LL) << endl;
	else
		cout << max(s-d-1, 0LL) << endl;

	return 0;
}