#include "bits/stdc++.h"
#define endl '\n'
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
int main(){
	int t, i, m;
	double p, limit = 1000000000.0, pp, pb;
	double sx;
	s(t);
 
	while (t--){
		scanf("%d %lf", &m, &p);
		if (m==1){
			printf("%lf 0.00\n", limit);
		} else if ( m == 2){
			printf("%lf %lf\n", limit * (1.0-p) , limit * p);
		} else {
			sx = 0; pb = p;
			for (i=1; i<m; i++){
				if (i%2 == 0)
					sx -= pb;
				else
					sx += pb;
				//printf("%lf\n", sx);
				pb *= p;
			}
			pp = limit * sx;
			if (m%2 == 0){
				printf("%lf %lf\n", limit - pp, pp);
			} else {
				printf("%lf %lf\n", limit - pp, pp);
			}
		}
	}
 
	return 0;
} 