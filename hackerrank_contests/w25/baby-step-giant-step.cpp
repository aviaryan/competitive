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
	ll t, i, q, a, b, d;
	ios_base::sync_with_stdio(0);
	cin >> q;
	while (q--){
		cin >> a >> b >> d;
		if (a > b) swap(a, b);
		t = d / b;
		if (d - b*t == 0)
			cout << t << endl;
		else if (a == d - b*t)
			cout << t+1 << endl;
		else {
			if (t == 0)
				cout << t+2 << endl;
			else
				cout << t+1 << endl;
		}
	}


	return 0;
}