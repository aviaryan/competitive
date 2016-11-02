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
	int t, i, n, m, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	int a[n], b[m];
	for (i=0; i<n; i++){
		cin >> a[i];
	}
	for (i=0; i<m; i++){
		cin >> b[i];
	}
	int ans = 0;
	for (i=1; i<=100; i++){
		for (j=0; j<n; j++)
			if (i % a[j] != 0)
				break;
		if (j != n) continue;
		for (j=0; j<m; j++)
			if (b[j] % i != 0)
				break;
		if (j != m) continue;
		ans++;
	}
	cout << ans;
	return 0;
}