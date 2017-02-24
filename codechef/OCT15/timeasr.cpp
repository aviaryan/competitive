#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lf\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int t, i;
	s(t);
	double m, num, ang, pt, pt2, modt;
	const double acc = 1.0/120.0;
	// eqs
	// - num + 5.5t
	// 360 - abs(up)

	while (t--){
		scanf("%lf", &m);
		for (i=0; i<12; i++){
			num = 30 * i;
			modt = num / 5.5;

			// abs num - 5.5t
			pt = round( (num - m) / 5.5 );
			if (pt <= modt && pt >= 0.0 && pt < 60.00){
				ang = fabs( -num + 5.5*pt );
				if ( fabs(ang-m) < acc )
					printf("%02d:%02d\n", i, (int) pt);
			}
			// 360 - (num - 5.5t)
			pt2 = round( (m - 360 + num) / 5.5 );
			if (pt != pt2 && pt2 <= modt && pt2 >= 0.0 && pt2 < 60.00){
				ang = fabs( 360 - fabs(-num + 5.5*pt2) );
				if ( fabs(ang-m) < acc )
					printf("%02d:%02d\n", i, (int) pt2);
			}

			// no abs
			pt = round( (num + m) / 5.5 );
			if (pt > modt && pt < 60.00){
				ang = fabs( -num + 5.5*pt );
				if ( fabs(ang-m) < acc )
					printf("%02d:%02d\n", i, (int) pt);
			}
			// 360 - 5.5t + num
			pt2 = round( (360 + num - m) / 5.5 );
			if (pt != pt2 && pt2 > modt && pt2 < 60.00){
				ang = fabs( 360 - fabs(-num + 5.5*pt2) );
				if ( fabs(ang-m) < acc )
					printf("%02d:%02d\n", i, (int) pt2);
			}
		}
	}

	return 0;
}