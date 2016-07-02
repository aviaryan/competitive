#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


ll arr[100000], mx[100000], max_r[100000], ans;

int main(){
	int t, i, n;
	s(t);

	while (t--){
		s(n);
		for (i=0; i<n; i++) 
			sl(arr[i]);
		ans = arr[0];
		mx[0] = arr[0];
		max_r[0] = 0;
		// p(ans);
		for (i=1; i<n; i++){
			max_r[i] = max(max(max_r[i-1], 0LL) + arr[i], mx[i-1]);
			mx[i] = max(mx[i-1], 0LL) + arr[i];
			ans = max(ans, max(max_r[i], mx[i]));
		}
		p(ans);
	}

	return 0;
}
