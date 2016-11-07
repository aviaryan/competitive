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
	int t, i, n, j, temp;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int arr[256][256];
	int sum;
	while (t--){
		cin >> n;
		for (i=0; i<2*n; i++){
			for (j=0; j<2*n; j++){
				cin >> arr[i][j];
			}
		}
		// solve
		sum = 0;
		for (i=0; i<n; i++){
			for (j=0; j<n; j++){
				temp = max(arr[i][j], arr[i][2*n-1-j]);
				temp = max(temp, arr[2*n-1-i][2*n-1-j]);
				temp = max(temp, arr[2*n-1-i][j]);
				sum += temp;
			}
		}
		cout << sum << endl;
	}

	return 0;
}