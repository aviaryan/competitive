#include "bits/stdc++.h"
#define endl '\n'
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


double PowMod(double bs, int n){ // base^n % modULO
    double ret = 1;
    double a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}


int main(){
	int t, i, m;
	double p, limit = 1000000000.0, pp, pb, imp1, imp2;
	double s1, s2;
	s(t);

	while (t--){
		scanf("%d %lf", &m, &p);
		if (m==1){
			printf("%lf 0.00\n", limit);
		} else if ( m == 2){
			printf("%lf %lf\n", limit * (1.0-p) , limit * p);
		} else if ( p == 1.0 ){
			if (m%2 == 0)
				printf("0.00 %lf\n", limit);
			else
				printf("%lf 0.00\n", limit);
		} else {
			pb = p*p;

			// x - xx + xxx - xxxx
			if (m%2 == 0){
				imp2 = PowMod(pb, (m-1)/2);
				imp1 = pb * imp2;
			} else {
				imp1 = imp2 = PowMod(pb, m/2);
			}
			s1 = p * ( 1 - imp1 ) / ( 1 - pb );
			s2 = pb * ( 1 - imp2 ) / ( 1 - pb );

			pp = limit * (s1 - s2);
			if (m%2 == 0){
				printf("%lf %lf\n", limit - pp, pp);
			} else {
				printf("%lf %lf\n", limit - pp, pp);
			}
		}
	}

	return 0;
}