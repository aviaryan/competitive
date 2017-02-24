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
	int t, i, j, len, sp, ep;
	//ios_base::sync_with_stdio(0);
	//cin >> t;
	char str[10000], largest, strc[10000];
	scanf("%d", &t);

	for (j=1; j<=t; j++){
		scanf("%s", str);
		len = strlen(str);
		if (len == 1){
			printf("Case #%d: %s\n", j, str);
			continue;
		}
		largest = str[0];
		sp = 5000;
		ep = 5000;
		strc[sp] = str[0];
		for (i=1; i<len; i++){
			if (str[i] >= largest){
				strc[sp-1] = str[i];
				sp--;
				largest = str[i];
			} else {
				strc[ep+1] = str[i];
				ep++;
			}
		}
		strc[ep+1] = '\0';
		printf("Case #%d: %s\n", j, &strc[sp]);
	}

	return 0;
}