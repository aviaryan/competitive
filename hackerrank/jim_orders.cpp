#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef map<int, vi> mii;

int main(){
	int t, i, ti, d;
	ios_base::sync_with_stdio(0);
	cin >> t;
	mii col;

	for (i=1; i<=t; i++){
		cin >> ti >> d;
		col[ti+d].push_back(i);
	}

	mii::iterator it;
	vi::iterator vit;
	for (it = col.begin(); it != col.end(); ++it)
		for (vit = (it->second).begin(); vit != (it->second).end(); ++vit)
			cout << *vit << ' ';

	return 0;
}