#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool arr[1001][1001];
bool suc = 0;
int c, a, b;

void solve(int g1, int g2){
	if (g1==c || g2==c){
		suc = 1;
		return;
	}
	if (arr[g1][g2] || suc)
		return;
	else
		arr[g1][g2] = 1;

	if ((a-g1) > g2) // this step is more likely for success
		solve(g1+g2, 0);
	else
		solve(a, g2-(a-g1));
	if ((b-g2) > g1)
		solve(0, g2+g1);
	else
		solve(g1-(b-g2), b);
	
	solve(a, g2);
	solve(g1, b);
	solve(g1, 0);
	solve(0, g2);
}

int main(){
	int t, i;
	cin >> t;

	while (t--){
		scanf("%d %d %d", &a, &b, &c);
		for (i=0; i<=a; i++)
			fill_n(arr[i], b+1, 0);
		suc = 0;
		solve(a, b);
		printf("%s\n", suc ? "YES" : "NO");
	}
	return 0;
}