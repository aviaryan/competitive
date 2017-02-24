#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
	int n,m,i,j,c,k;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	unsigned long long a[n];
	int b[m];

	for (i=0; i<n; i++)
		cin >> a[i];
	for (i=0; i<m; i++)
		cin >> b[i];

	for (i=0; i<m; i++){
		cin >> c;
		// calc
		/*j = n/b[i];
		for (;j>0;j--) {
			a[ j*b[i] - 1 ] = ( a[ j*b[i]-1 ] * c ) % MODN;
		}*/
		for (j=b[i]; j<=n; j+=b[i])
			a[j-1] = c*a[j-1]%MODULO;
	}

	for (i=0; i<n; i++)
		cout << a[i] << " ";
}