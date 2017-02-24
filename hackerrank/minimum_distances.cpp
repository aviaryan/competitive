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

	int pos[100000 + 1];
	fill_n(pos, 100000 + 1, -1);
	int mn = MODULO;

	for (i=0; i<n; i++){
		cin >> t;
		if (pos[t] != -1)
			mn = min(mn, i - pos[t]);
		pos[t] = i;
	}

	if (mn == MODULO)
		printf("-1\n");
	else
		printf("%d\n", mn);


	return 0;
}