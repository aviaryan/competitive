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
	int t, i, k, ans;
	//ios_base::sync_with_stdio(0);
	s(t);
	char num[100000+2];

	while (t--){
		scanf("%s", num);
		k = strlen(num);
		ans = 0;
		for (i=0; i<k; i++){
			if (num[i] != '4' && num[i] != '7')
				ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}