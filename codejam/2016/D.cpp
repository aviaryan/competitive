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
	int t, i, k, c, s, lc;
	scanf("%d", &t);

	for (lc=1; lc<=t; lc++){
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d: ", lc);
		for (i=1; i<=k; i++){
			printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}