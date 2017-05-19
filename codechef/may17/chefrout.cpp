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
	int t, i, len;
	s(t);
	char str[100000 + 1];
	bool fail;

	while (t--){
		scanf("%s", str);
		len = strlen(str);
		fail = false;
		for (i=1; i<len; i++){
			if ( (str[i-1] == 'S' && str[i] == 'C')
				|| (str[i-1] == 'E' && str[i] == 'C')
				|| (str[i-1] == 'S' && str[i] == 'E') )
				fail = true;
		}
		printf("%s\n", (fail) ? "no" : "yes");
	}

	return 0;
}
