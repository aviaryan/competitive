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
	int t, i, oc, zc;
	char str[100000+1];

	s(t);
	while (t--){
		scanf("%s", str);
		oc = 0; zc = 0;
		for (i=0; i<strlen(str); i++){
			if (str[i] == '0')
				zc++;
			else
				oc++;
		}
		if (zc == 1 || oc == 1){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}