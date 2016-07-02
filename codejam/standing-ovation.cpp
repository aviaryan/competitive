#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
ifstream fin("A-large.in");
ofstream fout("output.txt");

int main(){
	int t, n, bln, x, ans, i, j;
	fin >> t;
	char str[1002];

	for (j=1; j<=t; j++) {
		fin >> n;
		fin >> str;
		bln = 0;
		ans = 0;
		for (i=0; i<=n; i++){
			x = (int) str[i] - 48;
			if (bln < i){
				ans += (i-bln);
				bln += (i-bln);
			}
			bln += x;
		}
		fout << "Case #" << j << ": " << ans << endl;
	}
	return 0;
}