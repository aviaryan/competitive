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
	int t, i, x1, v1, x2, v2;
	ios_base::sync_with_stdio(0);
	cin >> x1 >> v1 >> x2 >> v2;

	// x1 + t * v1 = x2 + t * v2
	// x1 - x2 / v2 - v1 = t
	int dx = x1 - x2;
	int dv = v2 - v1;
	if (dx * dv >= 0){ // same sign
		if (dv == 0){
			if (dx == 0)
				printf("YES\n");
			else
				printf("NO\n");
		} else if (dx % dv == 0){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		printf("NO\n");
	}

	return 0;
}