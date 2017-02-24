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
	ll t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll arr[100000];
	ll hs, sum;

	while (t--){
		cin >> n;
		hs = 0;
		for (i=0; i<n; i++){
			cin >> arr[i];
			hs += arr[i];
		}
		sort(arr, arr+n);
		sum = hs;
		for (i=0; i<n; i++){
			sum -= arr[i];
			hs = max(hs, (1+i+1)*sum);
		}
		cout << hs << endl;
	}

	return 0;
}