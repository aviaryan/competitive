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
	ll t;
	ios_base::sync_with_stdio(0);
	cin >> t;

	ll row = 3, tk = 0;
	while (tk < t){
		tk += row;
		if (tk >= t){
			tk -= row;
			break;
		}
		row *= 2LL;
	}

	cout << row - (t - tk) + 1 << endl;  // row capactity - element position + 1

	return 0;
}