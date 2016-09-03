#include "bits/stdc++.h"
#include <tr1/unordered_set>
using namespace std::tr1;
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define d(a) printf(">> %d\n", a)
#define ds(s) printf("%s\n", s)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector <int> rels[1000+1];
bool cons[1001][1001];


bool solve(int n){
	int i, j;
	bool fail = false;
	// find first oppons
	for (i=1; i<=n; i++){
		for (j=i+1; j<=n; j++){
			if (!cons[i][j]) 
				break;
		}
		if (j <= n) 
			break;
	}
	int a = i, b = j, t;
	// d(a); d(b);
	vector<int>::iterator vi;
	queue <int> q1, q2;
	q1.push(a); q2.push(b);
	int grps[n+1];
	fill_n(grps, n+1, 0);
	grps[a] = 1; grps[b] = 2;
	// count renmn
	unordered_set <int> remn;
	unordered_set <int>::iterator sit;
	for (i=1; i<=n; i++)
		remn.insert(i);
	remn.erase(a);
	remn.erase(b);
	// find forced friends
	while (true){
		while ((!q1.empty()) || (!q2.empty())){
			// A
			if (q1.empty()){
				b = q2.front(); q2.pop();
				// loop
				for (sit=remn.begin(); sit != remn.end(); sit++){
					if (!cons[b][*sit]){
						grps[*sit] = 1;
						q1.push(*sit);
						remn.erase(sit);
					}
				}
				continue;
			} else {
				a = q1.front(); q1.pop();
			}
			// B
			if (q2.empty()){
				// loop
				for (sit=remn.begin(); sit != remn.end(); sit++){
					if (!cons[a][*sit]){
						grps[*sit] = 2;
						q2.push(*sit);
						remn.erase(sit);
					}
				}
				continue;
			} else {
				b = q2.front(); q2.pop();
			}
			// ds("here");
			//
			for (sit=remn.begin(); sit != remn.end(); sit++){
				if (cons[a][*sit] && !cons[b][*sit]){
					// ds("Asd");
					grps[*sit] = 1;
					q1.push(*sit);
					remn.erase(sit);
				} else if (cons[b][*sit] && !cons[a][*sit]) {
					// ds("avv");
					grps[*sit] = 2;
					q2.push(*sit);
					remn.erase(sit);
				} else if (!cons[a][*sit] && !cons[b][*sit]){
					// ds("fail");
					fail = true;
					break;
				}
			}
			// check for fail
			if (fail)
				break;
		}
		if (fail) 
			break;
		if (remn.empty())
			break;
		// d(a);
		// if elems still remaining
		if (!remn.empty()){
			q1.push(*remn.begin());
			remn.erase(remn.begin());
			grps[q1.front()] = 1;
		}
	}
	if (fail)
		return false;
	//
	// check correctness in the groups
	// 
	int gc[3] = {0, 0, 0};
	int grc[3] = {0, 0, 0};
	for (i=1; i<=n; i++){
		t = grps[i];
		grc[t]++;
		for (vi=rels[i].begin(); vi != rels[i].end(); vi++){
			if (grps[*vi] == t)
				gc[t]++;
		}
	}
	// d(gc[1]); d(gc[2]);
	if ( ( gc[1] == grc[1] * (grc[1]-1) ) && ( gc[2] == grc[2] * (grc[2]-1) ) )
		return true;
	else
		return false;
}


int main(){
	int t, i, n, m, a, b, ct;
	s(t);

	while (t--){
		scanf("%d %d", &n, &m);
		ct = 0;
		for (i=1; i<=n; i++){
			rels[i].clear();
			fill_n(cons[i], n+1, 0);
		}
		for (i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			if ((a == b) || cons[a][b]){
				continue;
			}
			rels[a].push_back(b);
			cons[a][b] = true;
			rels[b].push_back(a);
			cons[b][a] = true;
			ct++;
		}
		if (n < 3){
			printf("YES\n");
		} else if (ct == ((n * (n-1)) / 2)){
			printf("YES\n");
		} else if (solve(n)){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}