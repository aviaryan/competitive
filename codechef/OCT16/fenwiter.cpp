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
	int t, i, n, ans;
	s(t);
	char l1[1001], l2[1001], l3[1001];
	int l3onec, l2onec, l1onec, slen3, slen2, slen1, onepos, decrease;

	while (t--){
		scanf("%s %s %s %d", l1, l2, l3, &n);
		ans = 0; decrease = -MODULO; onepos = -1;

		slen3 = strlen(l3); l3onec = 0;
		for (i=slen3-1; i>=0; i--){
			if (l3[i] == '1') 
				l3onec++;
			if (onepos == -1 && l3[i] == '0')
				onepos = i;
		}

		if (decrease == -MODULO && onepos != -1){
			decrease = slen3-onepos-2;  // 1s actually increase if last is 0
		}

		slen2 = strlen(l2); l2onec = 0;
		for (i=slen2-1; i>=0; i--){
			if (l2[i] == '1') 
				l2onec++;
			if (onepos == -1 && l2[i] == '0')
				onepos = i;
		}

		if (decrease == -MODULO && onepos != -1){
			decrease = slen3 + slen2-onepos-2;
		}

		slen1 = strlen(l1); l1onec = 0;
		for (i=slen1-1; i>=0; i--){
			if (l1[i] == '1') 
				l1onec++;
			if (onepos == -1 && l1[i] == '0')
				onepos = i;
		}

		if (decrease == -MODULO && onepos != -1){
			decrease = slen3 + n*slen2 + slen1-onepos-2;
		}

		if (onepos == -1){ // full 1s
			ans = 1;
		} else {
			ans = l3onec + n * l2onec + l1onec - decrease;
		}
		p(ans);
	}

	return 0;
}