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
	int t, i, n, m, c, lmt, ans;
	s(t);

	while (t--){
		scanf("%d %d %d", &n, &m, &c);
		lmt = sqrt(c);
		ans = 0;
		for (i=1; i<=lmt; i++){
			if (c % i == 0){
				// row is i
				if ( (i <= n) && (c/i <= m) )
					ans ++;
				if (i == c/i)
					break;
				// row is c/i
				if ( (c/i <= n) && (i <= m) )
					ans ++;
			}
		}
		p(ans);
	}

	return 0;
}