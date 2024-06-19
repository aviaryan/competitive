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

int revInt(int a) {
	bool neg = (a < 0);
	if (neg) {
		a *= -1;
	}
	int rem = 0;
	int res = 0;
	while (a > 0) {
		rem = a % 10;
		res = res*10 + rem;
		a = a / 10;
	}
	if (neg) {
		res *= -1;
	}
	return res;
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);

	cin >> t;
	cout << revInt(t) << endl;

	return 0;
}