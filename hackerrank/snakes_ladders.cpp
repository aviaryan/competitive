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

vector <int> nodes[101];
int ladders[101];
int LT = 100;
int moves[101];
vector <int>::iterator vit;

int bfs_mm(){
	bool visits[LT+1];
	fill_n(visits, LT+1, false);
	queue<int> q;
	int qit;
	moves[1] = 0;
	q.push(1);
	visits[1] = 1;

	while (q.size() > 0){
		qit = q.front();
		q.pop();
		for (vit = nodes[qit].begin(); vit != nodes[qit].end(); vit++){
			if (!visits[*vit]){
				q.push(*vit);
				moves[*vit] = moves[qit]+1;
				visits[*vit] = 1;
				if (*vit == LT)
					return moves[*vit];
			}
		}
	}

	return -1;
}

int lader_recur(int k){
	if ( ladders[k] == 0 )
		return k;
	else
		return lader_recur( ladders[k] );
}

void makeGraph(){
	int i,j;
	for (i=0; i<=LT; i++)
		for (j=i+1; j<i+7; j++){
			if (j > LT) break;
			nodes[i].push_back(lader_recur(j));
		}
}

int main(){
	int t, i, n, m, s, l, a, b, ans;
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while (t--){

		fill_n(ladders, LT+1, 0);
		for (i=0; i<=LT; i++) nodes[i].clear();

		cin >> l;
		for (i=0; i<l; i++){
			cin >> a >> b;
			ladders[a] = b;
		}

		cin >> s;
		for (i=0; i<s; i++){
			cin >> a >> b;
			ladders[a] = b;
		}

		makeGraph();
		ans = bfs_mm();

		cout << ans << endl;
	}

	return 0;
}