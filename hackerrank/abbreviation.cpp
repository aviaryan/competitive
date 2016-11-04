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
	int t, i, j, slena, slenb;
	char temp;
	s(t);
	char a[1001], b[1001];
	bool dp[1001][1001];

	while (t--){
		scanf("%s %s", a, b);
		slena = strlen(a);
		slenb = strlen(b);
		fill_n(dp[0], 1001, false); dp[0][0] = true;
		for (i=1; i<=slena; i++){
			fill_n(dp[i], 1001, false);
			dp[i][0] = (a[i-1] < 97) ? false : dp[i-1][0];
			temp = (a[i-1] > 96) ? a[i-1]-32 : a[i-1];
			for (j=1; j<=i; j++){
				if (temp == b[j-1])
					dp[i][j] = dp[i-1][j-1];
				if (dp[i][j] == false && a[i-1] > 96)
					dp[i][j] = dp[i-1][j];
			}
		}
		if (dp[slena][slenb])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}