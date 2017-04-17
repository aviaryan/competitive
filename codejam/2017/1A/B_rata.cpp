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
	int t, i, n, p, tf, j;
	double rat[50];
	double pks[50][50], mpks[50][50];
	double per, perl;
	int ct, rem;
	int minn[50];
	ios_base::sync_with_stdio(0);
	cin >> t;

	for (tf=1; tf<=t; tf++){
		cin >> n >> p;
		for (i=0; i<n; i++){
			cin >> rat[i];
		}
		for (i=0; i<n; i++){
			per = 0.1 * (double) rat[i];
			for (j=0; j<p; j++){
				cin >> pks[i][j];
				rem = ((int) pks[i][j]) % ((int) rat[i]);
				perl = ( ((int) pks[i][j]) / ((int) rat[i]) ) * per;
				
				if (rem == 0){
					pks[i][j] = (int) pks[i][j] / (int) rat[i];
				} else if ( (rat[i] - rem) <= (perl+per) ){
					pks[i][j] = ((int) pks[i][j] / (int) rat[i]) + 1;
				} else if ( rem <= perl ){
					pks[i][j] = (int) pks[i][j] / (int) rat[i];
				} else {
					pks[i][j] = -1; // invalid
				}
			}
		}

		for (i=0; i<n; i++){
			for (j=0; j<p; j++){
				cout << pks[i][j] << " ";
			}
			cout << endl;
		}
		cout << "end";
		// solve
	}

	return 0;
}