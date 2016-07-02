#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int *a1, *a2, n, m;
int lcs = 0;
int lcsd[101][101];

void printLCS(){
	int i=0, j=0;
	while (i < n && j < m){
		if (a1[i] == a2[j])
			printf("%d ", a1[i]), i++, j++;
		else if (lcsd[i+1][j] >= lcsd[i][j+1])
			i++;
		else
			j++;
	}
}

int solve_LCS(){
	int i, j;
	for (i=0; i<=n; i++)
		fill_n(lcsd[i], m+1, 0);

	for (i=n-1; i>=0; i--)
		for (j=m-1; j>=0; j--){
			if (a1[i] == a2[j])
				lcsd[i][j] = 1 + lcsd[i+1][j+1];
			else
				lcsd[i][j] = max(lcsd[i][j+1], lcsd[i+1][j]);
		}

	printLCS();
	return lcsd[0][0];
}


int main(){
	int i;
	cin >> n >> m;
	int a[n], b[m], *temp;

	for (i=0; i<n; i++)
		scanf("%d", a+i);
	for (i=0; i<m; i++)
		scanf("%d", b+i);

	a1 = a, a2 = b;

	solve_LCS();

	return 0;
}