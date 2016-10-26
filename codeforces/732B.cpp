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
	int t, i, n, k;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int arr[n];
	for (i=0; i<n; i++)
		cin >> arr[i];
	int ans = 0;
	for (i=1; i<n; i++){
		if (arr[i] + arr[i-1] < k){
			ans += k - (arr[i]+arr[i-1]);
			arr[i] += k - (arr[i]+arr[i-1]);
		}
	}
	cout << ans << endl;
	for (i=0; i<n; i++)
		cout << arr[i] << " ";

	return 0;
}