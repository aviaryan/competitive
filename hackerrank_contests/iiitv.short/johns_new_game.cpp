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
	int t, i, j;
	s(t);
	char a[401], b[401];
	int cta[26], ctb[26], lna, lnb;
	ll ans, temp;

	while (t--){
		scanf("%s %s", a, b);
		fill_n(cta, 26, 0);
		fill_n(ctb, 26, 0);
		lna = strlen(a); lnb = strlen(b);
		if (lna > lnb) {
			p(0);
			continue;
		}
		for (i=0; i<lna; i++){
			cta[a[i] - 'a']++;
		}
		for (i=0; i<lnb; i++){
			ctb[b[i] - 'a']++;
		}
		ans = 1;
		for (i=0; i<26; i++){
			if (ctb[i] < cta[i]){ 
				ans = 0;
				break;
			}
			temp = 1;
			for (j=ctb[i]-cta[i]+1; j<=ctb[i]; j++) {
				temp = m(temp * ((ll)j));
			}
			ans = m(ans * temp);
		}
		printf("%lld\n", m(ans));
	}

	return 0;
}