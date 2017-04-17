#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a,b;

	while (fin >> a >> b)
		fout << a*2 << " " << b*2 << endl;

	return 0;
}