#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int s1, s2, q;
	ull ar;
	double l;
	cin >> l >> s1 >> s2 >> q;
	s1 = abs(s1-s2);
	l *= sqrt(2);
	double z = sqrt(2);
	while (q--){
		scanf("%llu", &ar);
		printf("%.5lf\n", (double) fabs(l - sqrt(ar)*z)/s1 );
		// ar = ( real_diag - (s1-s2)*t )^2 / 2
	}
	return 0;
}