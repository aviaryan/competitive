#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)

#define LT 1000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int arr[LT + 1];

int main(){
	int t, i, x, y, n, h;
	ll sum, mn;
	//ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		scanf("%d %d", &n, &h);
		fill_n(arr, n+1, 0);
		for (i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			arr[0] += 1;
			arr[x] -= 1;
			arr[y+1] += 1;
		}
		for (i=1; i<n; i++)
			arr[i] += arr[i-1];
		// for (i=0; i<n; i++)
		// 	printf("%d ", arr[i]);

		sum = 0; mn = 0;
		for (i=0; i<h; i++)
			sum += arr[i];
		mn = sum;
		for (i=0; i < (n-h); i++){
			sum += arr[i+h];
			sum -= arr[i];
			mn = min(mn, sum);
		}

		printf("%lld\n", mn);
	}

	return 0;
}