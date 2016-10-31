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


int main(){
	int t, i, n, m;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	multimap<int, int> comps;
	for (i=0; i<n; i++){
		cin >> t;
		comps.insert(make_pair(t, i));
	}
	pair<int, int> socks[m];
	for (i=0; i<m; i++){
		cin >> t;
		socks[i] = make_pair(t, i);
	}
	// solve
	int cans = 0, uans = 0;
	sort(socks, socks+m);
	int ctos[n], stoa[m];
	fill_n(ctos, n, 0); fill_n(stoa, m, 0);

	int tmp;
	for (i=0; i<m; i++){
		tmp = socks[i].first;
		while (tmp>1 && comps.find(tmp) == comps.end()){
			tmp = (tmp+1)/2;
			stoa[socks[i].second]++;
		}
		if (comps.find(tmp) != comps.end()){
			ctos[comps.find(tmp)->second] = socks[i].second + 1;
			uans += stoa[socks[i].second];
			cans ++;
			comps.erase(comps.find(tmp));
		} else {
			stoa[socks[i].second] = 0;
		}
	}
	
	// ans
	cout << cans << " " << uans << endl;
	for (i=0; i<m; i++)
		cout << stoa[i] << " ";
	cout << endl;
	for (i=0; i<n; i++)
		cout << ctos[i] << " ";

	return 0;
}