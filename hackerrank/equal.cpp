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

int arr[10000], n;

int solve(int incrs){
	int i, k, ans = (incrs>0) ? 1 : 0, prev = arr[0];
	for (i=1; i<n; i++){
		k = arr[i] + incrs;
		if (k > prev){
			while (prev + 5 <= k){
				prev += 5; incrs+=5; ans++;
			}
			while (prev + 2 <= k){
				prev += 2; incrs+=2; ans++;
			}
			while (prev + 1 <= k){
				prev += 1; incrs+=1; ans++;
			}
		}
	}
	return ans;
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int ans;

	while (t--){
		cin >> n;
		for (i=0; i<n; i++) 
			cin >> arr[i];
		sort(arr, arr+n);
		// solve
		ans = solve(0);
		// only possible to balance 1st element this way. all others will affect previous too
		ans = min(ans, solve(1));
		ans = min(ans, solve(2));
		ans = min(ans, solve(5));
		cout << ans << endl;
	}

	return 0;
}