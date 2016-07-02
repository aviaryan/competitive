#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, s, i, slen, slen2;
	cin >> t;
	char str[10001];

	while (t--){
		scanf("%s", str);
		slen = strlen(str);
		slen2 = slen/2;
		s=1;
		for (i=0; i<slen2; i++)
			if ( abs(str[i] - str[i+1]) != abs(str[slen-1-i] - str[slen-1-i-1]) ){
				s = 0;
				break;
			}
		printf("%s\n", s==1 ? "Funny" : "Not Funny");
	}

	return 0;
}