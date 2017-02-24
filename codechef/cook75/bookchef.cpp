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


int main(){
	int t, i, n, m, id, p;
	s(n);
	s(m);
	set <int> s;
	for (i=0; i<n; i++){
		s(t);
		s.insert(t);
	}

	char strs[m][101];
	map <int, int> pops;
	map <int, int> norms;
	for (i=0; i<m; i++){
		scanf("%d %d %s", &id, &p, strs[i]);
		if (s.find(id) != s.end()){
			pops.insert(make_pair(p, i));
		} else {
			norms.insert(make_pair(p, i));
		}
	}

	// print
	map <int, int>::reverse_iterator mit;
	for (mit = pops.rbegin(); mit != pops.rend(); mit++){
		printf("%s\n", strs[mit->second]);
	}
	for (mit = norms.rbegin(); mit != norms.rend(); mit++){
		printf("%s\n", strs[mit->second]);
	}
	return 0;
}