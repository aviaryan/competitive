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

struct edge {
	int node;
	int length;
};

struct edge createEdge(int node, int length){
	struct edge ed;
	ed.node = node;
	ed.length = length;
	return ed;
}


int main(){
	int t, i, n, m, a, b, wt, s, j;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;

	vector <struct edge> edges[n+1];
	bool taken[n+1];
	fill_n(taken, n+1, false);

	for (i=0; i<m; i++){
		cin >> a >> b >> wt;
		edges[a].push_back(createEdge(b, wt));
		edges[b].push_back(createEdge(a, wt));
	}

	cin >> s;

	int cmin, cmin_node;
	map <int, int> tp;
	map <int, int>::iterator mit, mit2;
	vector <struct edge>::iterator vecit;
	tp.insert(make_pair(s, 0));
	taken[s] = true;
	int ans = 0;
	while (tp.size() > 0){
		// find cur min
		cmin = 9999999;
		for (mit = tp.begin(); mit != tp.end(); mit++){
			if (mit->second < cmin){
				cmin = mit->second;
				cmin_node = mit->first;
				mit2 = mit;
			}
		}
		ans += cmin;
		tp.erase(mit2);
		// add all adjacent nodes
		for (vecit = edges[cmin_node].begin(); vecit != edges[cmin_node].end(); vecit++){
			if (taken[vecit->node] == false){
				tp.insert(make_pair(vecit->node, vecit->length));
				taken[vecit->node] = true;
			} else if ((mit = tp.find(vecit->node)) != tp.end()){
				mit->second = min(mit->second, vecit->length);
			}
		}
	}

	cout << ans << endl;

	return 0;
}