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

struct child {
	vector <int> fs;
	bool visited;
	int score;
};


int main(){
	int t, j, i, k, sp, cc, n, ans, pk, vib, ppk, sc, lc, j2, j2l;

	scanf("%d", &t);
	struct child bffs[1001];
	//int bffs[1001];
	bool visited[1001];
	int useless[10001], uct;
	map <int, int> rfs;

	for (lc=1; lc<=t; lc++){
		scanf("%d", &n);
		rfs.clear();

		for (i=1; i<=n; i++){
			bffs[i].fs.clear();
		}

		for (i=1; i<=n; i++){
			scanf("%d", &k);
			bffs[i].fs.push_back(k);
			bffs[k].fs.push_back(i);
			//bffs[i] = k;
			//rfs.insert( make_pair(k, i) );
			bffs[i].visited = false;
		}

		ans = 0;

		for (i=1; i<=n; i++){
			queue <int> q;
			for (k=1; k<=n; k++){
				bffs[k].visited = false;
				bffs[k].score = 0;
			}
			bffs[k].visited = true;

			for (vector<int>::iterator j=bffs[i].fs.begin(); j != bffs[i].fs.end(); j++){
				bffs[*j].visited = true;
				bffs[*j].score = 1;
				q.push(*j);
			}

			sc = 1;
			while (q.size() > 0){
				j2l = q.size();
				sc++;
				for(j2=0; j2<j2l; j2++) {
					k = q.front();
					q.pop();
					for (vector<int>::iterator j=bffs[k].fs.begin(); j != bffs[k].fs.end(); j++){
						if (bffs[*j].visited == true){
							ans = max(ans, sc - bffs[*j].score);
						} else {
							bffs[*j].visited = true;
							bffs[*j].score = sc;
							q.push(*j);
						}
					}
				}
			}
			// loop times
		}

		printf("Case #%d: %d\n", lc, ans);
		//printf("%d\n", t);
	}
	// end loop
}