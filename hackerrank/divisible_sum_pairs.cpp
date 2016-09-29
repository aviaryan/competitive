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
	int t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int arr[n];

	for (i=0; i<n; i++){
		cin >> arr[i];
	}

	int ans = 0;
	for (i=0; i<(n-1); i++){
		for (j=i+1; j<n; j++){
			if ( (arr[i] + arr[j]) % k == 0 ){
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}