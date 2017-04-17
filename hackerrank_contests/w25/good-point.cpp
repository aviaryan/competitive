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

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int a;
} elps;


int main(){
	int t, i, n, v, x1, y1, x2, y2, a;
	ios_base::sync_with_stdio(0);
	cin >> n;
	vector<pii> lines[n];
	for (i=0; i<n; i++){
		cin >> v;
		for (j=0; j<v; j++){
			cin >> x1 >> y1;
			lines[i].push_back(mp(x1, y1));
		}
	}
	cin >> m;
	elps pols[m];
	for (i=0; i<m; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> a;
		elps e;
		e.x1 = x1; e.y1 = y1; e.x2 = x2; e.y2 = y2; e.a = a;
		pols[i] = e;
	}

	// line - line
	

	return 0;
}