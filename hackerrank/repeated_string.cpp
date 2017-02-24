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
	int t, i;
	ll n;
	char str[101];
	// ios_base::sync_with_stdio(0);
	scanf("%s", str);
	scanf("%lld", &n);

	int slen = strlen(str);
	int rem = (n % (ll) slen);

	int cm = 0, crem = 0;
	for (i=0; i<slen; i++){
		if (str[i] == 'a') cm++;
		if (i < rem) crem = cm;
	}

	printf("%lld\n", (n / (ll)slen) * (ll) cm + (ll) crem);

	return 0;
}