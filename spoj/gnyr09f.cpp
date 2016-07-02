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
	int t, i, n, k, j, op;
	//ios_base::sync_with_stdio(0);
	s(t);

	// preprocess
	int arr[91][101*2];
	for (i=0; i<91; i++)
		for (j=2; j<202; j+=2){
			if (j==2){
				arr[i][j] = (i==0) ? 1 : 0;
				arr[i][j+1] = (i==0) ? 1 : 0;
			} else {
				arr[i][j] = arr[i][j-2] + arr[i][j-1]; // 0 leading case
				arr[i][j+1] = arr[i][j-2]; // 1 leading case - 0 in previous
				if (i > 0){
					arr[i][j+1] += arr[i-1][j-1];
				}
			}
		}


	while (t--){
		scanf("%d %d %d", &op, &n, &k);
		printf("%d %d\n", op, arr[k][n*2] + arr[k][n*2+1]);
	}

	return 0;
}