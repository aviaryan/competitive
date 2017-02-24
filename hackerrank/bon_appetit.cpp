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
	int t, i, n, k;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;

	double tr = 0;
	for (i=0; i<n; i++){
		cin >> t;
		if (i != k) tr += t;
	}

	double charged;
	cin >> charged;

	tr /= 2;
	if (tr == charged){
		printf("Bon Appetit\n");
	} else {
		printf("%d\n", (int) (charged - tr));
	}

	return 0;
}