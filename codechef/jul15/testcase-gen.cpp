#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ifstream fin("input.txt");
ofstream fout("testcase.txt");

int main(){
	int t, i, j, k;
	ios_base::sync_with_stdio(0);
	
	t = 1;
	fout << t << endl;

	while (t--){
		int n = 9;
		int m = 1000;

		fout << n << " " << m << endl;

		fout << 0.12;
		for (i=1; i<m; i++)
			fout << " " << 0.12;
		fout << endl;

		for (i=1; i<n; i++){
			fout << "0.11";
			for (j=1; j<m; j++)
				fout << " " << "0.11";
			fout << endl;
		}
	}


	return 0;
}