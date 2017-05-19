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
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int arr[100000 + 1];

	while (t--){
		cin >> n;
		for (i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		cout << n - arr[n-1] << endl;
	}

	return 0;
}