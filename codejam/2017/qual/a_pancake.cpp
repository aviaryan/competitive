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
	int t, i, k, j, tf, slen, ct;
	ios_base::sync_with_stdio(0);
	cin >> t;
	char str[1001];

	for (tf=1; tf<=t; tf++){
		cin >> str >> k;
		slen = strlen(str);
		ct = 0;
		for (i=0; i<=(slen-k); i++){
			if (str[i] == '-'){
				ct++;
				for (j=i; j<i+k; j++){
					str[j] = (str[j] == '-') ? '+' : '-';
				}
			}
		}
		// check
		for (i=slen-k; i<slen; i++){
			if (str[i] == '-'){
				ct = -1;
				break;
			}
		}
		if (ct == -1){
			cout << "Case #" << tf << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << tf << ": " << ct << endl;
		}
	}

	return 0;
}
