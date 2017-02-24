#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

#define LT 100000
typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, m, i2;
	ll x,y,my;
	ll yaar[LT];
	int order[LT];
	ios_base::sync_with_stdio(0);
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);
		for (i=0; i<n; i++){
			scanf("%d", &m);
			my = -99999999999;
			for (i2=0; i2<m; i2++){
				scanf("%lld %lld", &x, &y);
				if (y>my) my=y;
			}
			if (my<0)
				yaar[i] = (my*LT) - ((ll) i);
			else
				yaar[i] = (my*LT) + ((ll) i);
		}
		sort( yaar, yaar+n );

		// CALC result
		for (i=0; i<n; i++){
			x = yaar[i]%LT;
			if (x<0) x = -x;
			order[x] = i;
		}

		// op it
		for (i=0; i<n; i++) printf("%d ", order[i]);
		printf("\n");
	}
	return 0;
}