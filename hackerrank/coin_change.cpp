#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n, j, i, m;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	int arr[m];
	ll ans[m][n+1], a, k;

	for (i=0; i<m; i++){
		cin >> arr[i];
		ans[i][0] = 1;
	}

	for (i=1; i<=n; i++)
		for (j=0; j<m; j++){
			if ( (i - arr[j]) >= 0 )
				a = ans[j][i - arr[j]];
			else
				a = 0;
			if (j > 0)
				k = ans[j-1][i];
			else
				k = 0;
			ans[j][i] = a + k;
		}
	
	cout << ans[m-1][n];
	return 0;
}