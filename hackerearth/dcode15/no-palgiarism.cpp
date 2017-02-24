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


int lcs(char *X,char *Y,int m,int n)
{
	 int lc[m+1][n+1];
	 int i, j;

	 for (i=0; i<=m; i++)
	 {
		 for (j=0; j<=n; j++)
		 {
			 if (i == 0 || j == 0)
				 lc[i][j] = 0;
			 else if (X[i-1] == Y[j-1])
				 lc[i][j] = lc[i-1][j-1] + 1;
			 else
				 lc[i][j] = max(lc[i-1][j], lc[i][j-1]);
		 }
	 }
	 return lc[m][n];
}


int main(){
	int t, i;
	char s1[201], s2[201];
	gets(s1);
	gets(s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	printf("%d", l1  + l2 - 2*lcs(s1, s2, strlen(s1), strlen(s2)));

	return 0;
}

