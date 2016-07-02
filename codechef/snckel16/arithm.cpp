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
	int t, i;
	ll n, c, mt, ft;
	// ios_base::sync_with_stdio(0);
	s(t);
	bool suc;

	while (t--){
		scanf("%lld %lld", &n, &c);
		suc = false;
		if (n == 1){
			suc = true;
		} else if (c % n == 0){
			if (n%2 == 1){
				mt = c/n;
				if ((mt - n/2) > 0)
					suc = true;
			} else {
				mt = c/n;
				ft = mt - (2 * ((n/2)-1) + 1);
				if (ft > 0)
					suc = true;
			}
		} else {
			if (n%2 == 0 && c%(n/2) == 0){
				// happends when d=odd n=even
				mt = (c/n);  // n=4 s=50
				ft = mt - (n/2 - 1);
				if (ft > 0)
					suc = true;
			}
		}
		if (suc)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}