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
	int t, i;
	ios_base::sync_with_stdio(0);
	
	int n = 100000;
	int q = 1;

	fout << n << " " << q << endl;

	for (i=1; i<=n; i++)
		fout << i << " ";
	fout << endl;

	fout << "4 1 " << n << endl;


	return 0;
}