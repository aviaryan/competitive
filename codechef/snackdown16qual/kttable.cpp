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
	int t, i, n, ans;
	s(t);
	int a[10000], b[10000], bc;

	while (t--){
		s(n);
		for (i=0; i<n; i++)
			s(a[i]);
		for (i=0; i<n; i++)
			s(b[i]);
		// make ans
		ans = 0;
		if (a[0] >= b[0]) ans++;
		for (i=1; i<n; i++)
			if ((a[i]-a[i-1]) >= b[i]) ans++;
		p(ans);
	}

	return 0;
}