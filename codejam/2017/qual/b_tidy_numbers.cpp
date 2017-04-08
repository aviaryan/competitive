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
	int t, i, tf, i2;
	int n, slen;
	ios_base::sync_with_stdio(0);
	cin >> t;
	char str[20];

	for (tf=1; tf<=t; tf++){
		cin >> str;
		slen = strlen(str);
		for (i2=0; i2<20; i2++){
			for (i=0; i<(slen-1); i++){
				if (str[i] > str[i+1]){
					str[i]--;
					for (i=i+1; i<slen; i++)
						str[i] = '9';
					break;
				}
			}
		}
		if (str[0] == '0' && slen > 1){
			for (i=1; i<=slen; i++){
				str[i-1] = str[i];
			}
		}
		cout << "Case #" << tf << ": " << str << endl;
	}
	return 0;
}