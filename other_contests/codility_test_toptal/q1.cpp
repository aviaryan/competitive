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


void getChange(double m, double p) {
	int rem = (100.0*m - 100.0*p);
	// cout << rem << endl;
	int denoms[6] = {1, 5, 10, 25, 50, 100};
	int ret[6] = {0, 0, 0, 0, 0, 0};
	int i;
	for (i=5; i>=0; i--) {
		// if (rem == 0.0) break;
		while (rem >= denoms[i]) {
			ret[i]++;
			rem -= denoms[i];
		}
	}

	// print the solution
	for (i=0; i<6; i++){
		cout << ret[i] << " ";
	}
	cout << endl;
}

int main(){
	int t, i;
	getChange(5, 0.99);
	getChange(3.14, 1.99);
	getChange(4, 3.14);
	getChange(0.45, 0.34);

	return 0;
}