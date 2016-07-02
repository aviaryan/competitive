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
	int t, i, n, a, ans, sp, ep, mn;
	int lsp, lep;
	s(t);
	char str[100000+1];
	int arr[100000];

	while (t--){
		s(n);
		ans = 0;
		scanf("%s", str);
		for (i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		// starting offs
		for (i=0; i<n; i++){
			if (str[i] == '1') break;
		}
		ans += arr[i] - arr[0];
		sp = i;
		// end offs
		for (i=n-1; i>=0; i--){
			if (str[i] == '1') break;
		}
		ans += arr[n-1] - arr[i];
		ep = i;
		// 1....1
		for (i=sp; i<ep; i++){
			lsp = i;
			for (i=lsp+1; i<=ep; i++)
				if (str[i] == '1') break;
			lep = i;
			mn = MODULO;
			for (i=lsp; i<lep; i++){
				mn = min(mn, (arr[i] - arr[lsp]) + (arr[lep] - arr[i+1]));
			}
			ans += mn;
			i = lep-1;
		}
		p(ans);
	}

	return 0;
}