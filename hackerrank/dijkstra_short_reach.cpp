#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define unordered_map map
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector < pair<int, int> > nodes[3001]; // use a pair vector
int dists[3001];
bool visited[3001];

void dijkstra_shortest(int s, int n){
	multimap <int,int> diss; // for cur dists
	diss.insert( make_pair(0,s) );
	fill_n(visited, n+1, false);
	fill_n(dists, n+1, -1); // for non-visiteds default
	vector < pair<int, int> >::iterator miit;
	multimap <int, int>::iterator mmiit;
	int curdis, mnode;

	while (diss.size() > 0){
		mmiit = diss.begin();
		mnode = mmiit->second;
		diss.erase(mmiit);
		if (visited[mnode] == 1)
			continue;
		else {
			curdis = mmiit->first;
			dists[mnode] = curdis;
			visited[mnode] = 1;
		}
		for (miit = nodes[mnode].begin(); miit != nodes[mnode].end(); miit++){
			if (!visited[miit->first])
				diss.insert( make_pair(miit->second + curdis, miit->first) );
		}
	}
}

int main(){
	int t, i, n, m, a, b, r, s;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n >> m;
		for (i=1; i<=n; i++) nodes[i].clear();
		for (i=0; i<m; i++){
			cin >> a >> b >> r;
			nodes[a].push_back( make_pair(b, r) );
			nodes[b].push_back( make_pair(a, r) ); // duplicates handled in djikstra's ordered set
		}
		cin >> s;
		dijkstra_shortest(s, n);
		for (i=1; i<=n; i++){
			if (i==s) continue;
			cout << dists[i] << " ";
		}
		cout << endl;
	}

	return 0;
}