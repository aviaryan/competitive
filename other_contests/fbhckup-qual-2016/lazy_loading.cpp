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
	int arr[100], ans, fused, cas=0;

	while (t--){
		cin >> n;
		cas++;
		for (i=0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr, arr+n);
		ans = 0; fused = 0;

		for (i=n-1; i>=0; i--){
			if (i+1 <= fused)
				break;
			if (arr[i] >= 50) {
				ans++;
			} else {
				fused += ceil((double) (50 - arr[i]) / (double) arr[i]);
				if (fused >= i+1)
					break;
				else
					ans++;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}

	return 0;
}