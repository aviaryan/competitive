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
	int t, i, len, hf;
	bool fail=false;
	s(t);
	char str[12345+1];

	while (t--){
		scanf("%s", str);
		len = strlen(str);
		fail = false;
		hf = len/2;
		for (i=0; i<hf; i++){
			if (str[i] == '.'){
				if (str[len-i-1] == '.'){
					str[len-i-1] = 'a';
					str[i] = 'a';
				} else {
					str[i] = str[len-i-1];
				}
			} else {
				if (str[len-i-1] == '.'){
					str[len-i-1] = str[i];
				} else if (str[len-i-1] != str[i]){
					fail = true;
					break;
				}
			}
		}
		if (len%2 == 1 && str[hf] == '.'){
			str[hf] = 'a';
		}
		if (fail){
			printf("-1\n");
		} else {
			printf("%s\n", str);
		}
	}

	return 0;
}