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

char a[1000000+1], b[1000000+1];

int main(){
	int t, i, zc, oc, os, zs, ans, len;
	s(t);

	while (t--){
		scanf("%s", a);
		scanf("%s", b);
		len = strlen(a);
		zc = 0;
		oc = 0;
		os = 0;
		zs = 0;
		ans = 0;
		for (i=0; i<len; i++){
			if (a[i] == '0' && b[i] == '1'){
				zc++;
			} else if (a[i] == '1' && b[i] == '0'){
				oc++;
			} else if (a[i] == '1'){
				os++;
			} else
				zs++;
		}
		// solve
		if (zc > oc){
			ans = oc + (zc-oc); // xor + (and/or)
			if (oc == 0 && os == 0)
				ans = -1;
		} else if (oc > zc) {
			ans = zc + (oc-zc);
			if (zc == 0 && zs == 0)
				ans = -1;
		} else {
			ans = zc;
		}
		// print
		if (ans < 0){
			printf("Unlucky Chef\n");
		} else {
			printf("Lucky Chef\n%d\n", ans);
		}
	}

	return 0;
}