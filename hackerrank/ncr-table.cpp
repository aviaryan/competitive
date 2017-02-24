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
	int t, i, j, n;
	ios_base::sync_with_stdio(0);
	cin >> t;

	// preprocess
	for (i=0; i<=1000; i++) // K
		for (j=0; j<=1000; j++){ // N
			if (i==0)
				arr[i][j] = 1;
			else if (j==0)
				arr[i][j] = 1;
			else
				arr[i][j] = m(arr[i][j-1] + arr[i-1][j]);
		}


	while (t--){
		cin >> n;
		i = 0; j = n;
		while (j >= 0){
			cout << arr[i][j] << " ";
			i++; j--;
		}
		cout << endl;
	}
	return 0;
}