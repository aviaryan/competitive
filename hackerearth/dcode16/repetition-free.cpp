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

bool check_rep(ll n){
	bool att[10];
	fill_n(att, 10, false);

	ll s=0, r;
	while (n){
		r = n%10;
		if (r==0)
			return false;
		if (!att[r])
			att[r] = true;
		else
			return false;
		s = s*10 + r;
		n = n/10;
	}
	return true;
}

int main(){
	ll i, t;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll lt = ((ll)MODULO)*20;

	for (i=t+1; i<lt; i++){
		if (check_rep(i)){
			printf("%lld\n", i);
			break;
		}
		if ((i - t) > 10000000){
			printf("0\n");
			break;
		}
	}

	return 0;
}