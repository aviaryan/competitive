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
	int t, i, k, r;
	ios_base::sync_with_stdio(0);
	cin >> k >> r;

	for (i=1; i<=9; i++){
		if ( (k*i) % 10 == r || (k*i) % 10 == 0 )
			break;
	}

	cout << i << endl;

	return 0;
}