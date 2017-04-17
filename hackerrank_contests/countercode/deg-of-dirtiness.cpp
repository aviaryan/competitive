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
	int t, i, n, m;
	int tms, r, ans, off;
	//ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		scanf("%d %d", &n, &m);
		tms = m/n;
		if (m%n == 0)
			r = n;
		else
			r = m%n;
		off = r/2;
		if (r%2 == 0)
			ans = (n%2==1 && tms%2==1) ? off : n-off+1;
		else
			ans = (n%2==1 && tms%2==1) ? n-off : off+1;
		printf("%d %d\n", ans, m%n==0 ? tms-1 : tms);
	}

	return 0;
}