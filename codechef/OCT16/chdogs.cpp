#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define PI 3.14159265
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	double s,v;
	s(t);

	while (t--){
		scanf("%lf %lf", &s, &v);
		printf("%.10lf\n", s / (v + v * cos(60.0 * PI / 180.0)));
	}

	return 0;
}