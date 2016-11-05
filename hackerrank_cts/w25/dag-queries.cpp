#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define vi vector<int>
#define LT 100001
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool visited[LT];
vi arr[LT];
int vals[LT];
int n;

void dfs(int u, int x, bool md){
	fill_n(visited, n+1, false);
	queue <int> q;
	int front;
	vi::iterator vit;
	q.push(u); visited[u] = true;
	while (!q.empty()){
		front = q.front();
		q.pop();
		if (md)
			vals[front] = x;
		else if (vals[front] > x)
			vals[front] = x;
		for (vit = arr[front].begin(); vit != arr[front].end(); vit++){
			if (!visited[*vit]){
				visited[*vit] = true;
				q.push(*vit);
			}
		}
	}
}

int main(){
	int t, i, m, q, u, v, x, op;
	scanf("%d %d %d", &n, &m, &q);
	fill_n(vals, n+1, 0);
	for (i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		arr[u].push_back(v);
	}
	while (q--){
		scanf("%d", &op);
		if (op < 3){
			scanf("%d %d", &u, &x);
			dfs(u, x, (op==1));
		} else {
			scanf("%d", &u);
			printf("%d\n", vals[u]);
		}
	}

	return 0;
}