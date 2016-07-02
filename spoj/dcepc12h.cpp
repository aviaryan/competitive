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
	int t, i, k;
	s(t);
	double n;

	while (t--){
		scanf("%lf %d", &n, &k);
		printf("%.6lf\n", (n+1)/2);
	}

	return 0;
}