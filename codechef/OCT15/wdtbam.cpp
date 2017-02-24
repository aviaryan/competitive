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
	int t, i, n, j, c, mx;
	s(t);
	char q[1001], a[1001];
	int arr[1001];

	while (t--){
		s(n);
		scanf("%s", q);
		scanf("%s", a);
		c = 0;
		for (j=0; j<n; j++){
			if (q[j] == a[j])
				c++; // yeah
		}
		mx = -1;
		for (i=0; i<=n; i++){
			scanf("%d", &j);
			if (i <= c)
				mx = max(mx, j);
		}
		if (n == c)
			printf("%d\n", j);
		else
			printf("%d\n", mx);
	}

	return 0;
}