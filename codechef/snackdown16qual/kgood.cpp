#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define d(a) printf("_%d_", a);
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, j, len, k, cur, ans;
	char str[100000+1];
	int ct[26];
	s(t);

	while (t--){
		scanf("%s", str);
		s(k);
		for (i=0; i<26; i++) 
			ct[i] = 0;
		len = strlen(str);
		for (i=0; i<len; i++) 
			ct[(int) str[i] - 97]++;
		sort(ct, ct+26);
		ans = 1000000;
		for (i=0; i<26; i++){
			// remove 0 occs
			if (ct[i] == 0) continue;
			cur = 0;
			for (j=25; j>=i; j--){
				if ((ct[j] - ct[i]) > k)
					cur += (ct[j] - (ct[i] + k));
				else
					break;
			}
			for (j=0; j<i; j++)
				cur += ct[j];
			ans = min(cur, ans);
		}
		p(ans);
	}

	return 0;
}