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

vector <int> nodes[401]; // use a pair vector
int edgewt[401][401];
int dists[401][401];
bool visited[401];

// floyd warshall is v^3
// this is v*v*log(v)
// a modified version of dj shortest reach
void dijkstra_shortest(int s, int n){
	multimap <int,int> diss; // for cur dists
	diss.insert( make_pair(0,s) );
	fill_n(visited, n+1, false);
	fill_n(dists[s], n+1, -1); // for non-visiteds default
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
			dists[s][mnode] = curdis;
			visited[mnode] = 1;
		}
		for (vector<int>::iterator vit = nodes[mnode].begin(); vit != nodes[mnode].end(); vit++){
			if (!visited[*vit])
				diss.insert( make_pair(edgewt[mnode][*vit] + curdis, *vit) );
		}
	}
}

int main(){
	int t, i, n, m, a, b, r, s, q;
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (i=0; i<m; i++){
		cin >> a >> b >> r;
		nodes[a].push_back(b);
		edgewt[a][b] = r;
	}

	for (i=1; i<=n; i++)
		dijkstra_shortest(i, n);

	cin >> q;
	for (i=0; i<q; i++){
		cin >> a >> b;
		cout << dists[a][b] << endl;
	}

	return 0;
}