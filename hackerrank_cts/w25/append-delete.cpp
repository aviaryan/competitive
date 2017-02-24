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
	int t, i, k;
	char s1[101], s2[101];
	scanf("%s %s %d", s1, s2, &k);
	int l1 = strlen(s1), l2 = strlen(s2);
	if (k >= (l1 + l2)){
		printf("Yes\n");
		return 0;
	}
	// real case
	for (i=0; i<min(l1, l2); i++){
		if (s1[i] != s2[i])
			break;
	}
	int same = i;
	k -= (l1 - same) + (l2 - same);
	if (k < 0)
		printf("No\n");
	else if (k % 2 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}