#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, n, slen, z, d, i;
	cin >> t;
	char str[101], ch;
	int score, ans;

	while (t--){
		scanf("%s%c%d", str, &ch, &n);
		score = 0, ans=0;
		slen = strlen(str);
		for (i=0; i<slen; i++)
			score += (str[i] == 'T' ? 2 : 1);
		n = 12*n;
		for (i=1; i<=n; i++){
			z = (n-i)/score;
			if (z==0) break;
			else {
				d = n - (z*score + i);
				i += d;
				ans += z * (d+1);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}