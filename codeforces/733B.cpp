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
	int lc = 0, rc = 0;
	int ls[n], rs[n];
	for (i=0; i<n; i++){
		cin >> ls[i] >> rs[i];
		lc += ls[i]; rc += rs[i];
	}

	int beauty = abs(lc - rc), temp, ans = 0;
	for (i=0; i<n; i++){
		temp = abs( (lc - ls[i] + rs[i]) - (rc - rs[i] + ls[i]) );
		if (temp > beauty){
			ans = i+1;
			beauty = temp;
		}
	}

	p(ans);

	return 0;
}