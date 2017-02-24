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

typedef pair<int,int> pii;

int visited[3000+1];
vector <int> nodes[3000+1];

// if a can already reach b then another edge will add a cycle
bool checkCycle(int a, int b, int lc){
	queue <int> q;
	q.push(a); visited[a] = lc;
	vector<int>::iterator vi;
	int cur;
	while (q.size() > 0){
		cur = q.front();
		q.pop();
		for (vi = nodes[cur].begin(); vi != nodes[cur].end(); vi++){
			if (*vi == b) return false;
			if (visited[*vi] != lc){
				visited[*vi] = lc;
				q.push(*vi);
			}
		}
	}
	return true;
}

int main(){
	int t, i, n, m, wt, a, b;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;

	multimap <int, pii> edges;
	multimap <int, pii>::iterator it;

	for (i=0; i<m; i++){
		cin >> a >> b >> wt;
		edges.insert(make_pair(wt, make_pair(a, b)));
	}

	for (i=0; i<n; i++) visited[i] = 0;

	int lc = 0, count = 0, sum = 0;
	for (it = edges.begin(); it != edges.end(); it++){
		lc++;
		if (checkCycle((a=it->second.first), (b=it->second.second), lc)){
			count++;
			sum += it->first;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		if (count == n-1) break;
	}

	cout << sum << endl;
	return 0;
}