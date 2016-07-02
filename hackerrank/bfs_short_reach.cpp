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

set <int> nodes[1001]; // bcoz input had duplicates
int dists[1001];

void bfs(int s, int n){
	bool visits[n+1];
	fill_n(visits, n+1, false);
	queue<int> q;
	int qit;
	set<int>::iterator vit;
	fill_n(dists, n+1, -1);
	dists[s] = 0;
	q.push(s);

	while (q.size() > 0){
		qit = q.front();
		q.pop();
		for (vit = nodes[qit].begin(); vit != nodes[qit].end(); vit++){
			if (!visits[*vit]){
				q.push(*vit);
				dists[*vit] = dists[qit]+6; // ac problem
				visits[*vit] = 1;
			}
		}
	}

}

int main(){
	int t, i, n, m, a, b, s, e=0;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n >> m;
		for (i=1; i<=n; i++)
			nodes[i].clear();
		for (i=0; i<m; i++){
			cin >> a >> b;
			nodes[a].insert(b);
			nodes[b].insert(a);
		}
		cin >> s;
		bfs(s, n);
		for (i=1; i<=n; i++){
			if (i==s) continue;
			cout << dists[i] << " ";
		}
		cout << endl;
	}

	return 0;
}