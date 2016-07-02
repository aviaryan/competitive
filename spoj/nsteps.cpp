#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, x, y;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> x >> y;
		if (x - y == 0 || x-y == 2){
			if (x%2 == 0)
				cout << x+y << endl;
			else
				cout << x+y-1 << endl;
		} else
			cout << "No Number" << endl;
	}
	return 0;
}