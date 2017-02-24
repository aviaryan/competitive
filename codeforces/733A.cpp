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
	// ios_base::sync_with_stdio(0);
	char str[101];
	scanf("%s", str);
	int len = strlen(str);
	int prev = -1, mx = 0;
	for (i=0; i<len; i++){
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y'){
			mx = max(mx, i - prev);
			prev = i;
		}
	}
	mx = max(mx, len - prev);
	printf("%d\n", mx);

	return 0;
}