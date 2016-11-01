#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define pii pair<int,int>
#define mp make_pair
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, a, b, c;
	ios_base::sync_with_stdio(0);
	cin >> n;
	map <pii, vector<pii> > objs;
	int mx=0, m1_i = -1, m2_i = -1;

	for (i=0; i<n; i++){
		cin >> a >> b >> c;
		if (min(a, min(b, c)) > mx){
			mx = min(a, min(b, c));
			m1_i = i;
		}
		// store
		if (a > b) swap(a, b);
		objs[mp(a, b)].push_back(mp(c, i));
		if (c != b){
			if (a > c)
				objs[mp(c, a)].push_back(mp(b, i));
			else
				objs[mp(a, c)].push_back(mp(b, i));
		}
		if (c != a && b != a){
			if (b > c) swap(b, c);
			objs[mp(b, c)].push_back(mp(a, i));
		}
	}

	// solve
	int tmp, tmp2, tmp3;
	map <pii, vector<pii> >::iterator it;
	for (it=objs.begin(); it != objs.end(); it++){
		tmp = it->second.size();
		if (tmp > 1){
			sort(it->second.begin(), it->second.end());
			tmp2 = it->second[tmp-1].first + it->second[tmp-2].first;
			tmp3 = min(it->first.first, min(it->first.second, tmp2));
			if (tmp3 > mx){
				mx = tmp3;
				m1_i = it->second[tmp-1].second;
				m2_i = it->second[tmp-2].second;
			}
		}
	}

	// print
	if (m2_i == -1){
		cout << "1\n" << m1_i+1 << endl;
	} else {
		cout << "2\n" << m1_i+1 << " " << m2_i+1 << endl;
	}

	return 0;
}