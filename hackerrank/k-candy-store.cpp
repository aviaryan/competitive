#include "bits/stdc++.h"
#define MODULO 1000000000
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int arr[1001][1001];


int main(){
	int t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> t;

	// preprocess
	for (i=1; i<=1000; i++) // K
		for (j=1; j<=1000; j++){ // N
			if (i==1)
				arr[i][j] = j;
			else if (j==1)
				arr[i][j] = 1;
			else
				arr[i][j] = m(arr[i][j-1] + arr[i-1][j]);
		}

	while (t--){
		cin >> n >> k;
		cout << arr[k][n] << endl;
	}

	return 0;
}