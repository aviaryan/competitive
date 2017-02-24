#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, a, b, c;
	ios_base::sync_with_stdio(0);
	
	cin >> a >> b >> c;
	while (!(a == 0 && b == 0 && c == 0)){
		if ((b-a == c-b) && c-b != 0)
			cout << "AP " << c + (c-b) << endl;
		else
			cout << "GP " << (c * c)/b << endl;
		cin >> a >> b >> c;
	}

	return 0;
}