#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int t, n, i, j;
	int arr[50001], pre, cur;
	ull ans;

	cin >> t;
	while (t--){
		cin >> n;
		fill_n(arr, n+1, 0);
		ans = 1, pre = 0;

		for (i=0; i<n; i++)
			scanf("%d", &j), arr[j]++;
	
		for (i=0; i<n; i++){
			cur = arr[i] + pre;
			if (cur - i < 1){
				ans = 0; break;
			} else
				ans = (ans * (cur-i)) % MODULO;
			pre = cur;
		}

		printf("%llu\n", ans);
	}
	return 0;
}