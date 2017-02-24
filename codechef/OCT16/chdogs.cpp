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
	long double s,v;
	s(t);

	while (t--){
		scanf("%Lf %Lf", &s, &v);
		printf("%.10Lf\n", (2.0/3.0) * (s/v));
	}

	return 0;
}