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

vector <int> nodes[10001];
int ladders[10001];
int LT;
int moves[10001];
int rec;
vector <int>::iterator vit;

int bfs_mm(){
	bool visits[LT+1];
	fill_n(visits, LT+1, false);
	queue<int> q;
	int qit;
	moves[0] = 0;
	q.push(0);
	visits[0] = 1;

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

int lader_recur(int k, int st){
	rec++;
	if (k == st && rec > 1)
		return -1;
	if ( ladders[k] == 0 )
		return k;
	else
		return lader_recur( ladders[k] , st );
}

void makeGraph(){
	int i,j,m;
	for (i=0; i<LT; i++)
		for (j=i+1; j<i+7; j++){
			if (j > LT) break;
			rec = 0;
			m = lader_recur(j, j);
			if (m != -1)
				nodes[i].push_back(m);
		}
}

int main(){
	int t, i, n, m, s, l, a, b, ans;
	//ios_base::sync_with_stdio(0);
	
	while(scanf("%d %d %d %d", &n, &m, &s, &l) == 4){ // THE PREFEABBLE INPUT METHOD (SOME PROLEM WITH CIN.EOF AND IOS_BASE I GUESS)
		LT = n*m;

		fill_n(ladders, LT+1, 0);
		for (i=0; i<=LT; i++) nodes[i].clear();

		for (i=0; i<s; i++){
			scanf("%d %d", &a, &b);
			ladders[a] = b;
		}
		for (i=0; i<l; i++){
			scanf("%d %d", &a, &b);
			ladders[a] = b;
		}
		makeGraph();

		printf("%d\n", bfs_mm());
	}

	return 0;
}