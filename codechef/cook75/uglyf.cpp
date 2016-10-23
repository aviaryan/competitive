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

int ans, tans;
int l1, l2;
set <int> s1c[26];
set <int> s2c[26];
// centres and left, right
// sides

void solve(set<int>::iterator s1it, set<int>::iterator s2it, int i){
	if (s1it == s1c[i].end() || s2it == s2c[i].end())
		return;
	tans = abs(l1-*s1it-1 - (l2-*s2it-1)) + abs(*s1it - (l2-*s2it-1)) + abs(*s1it - *s2it) + abs(l1-*s1it-1 - *s2it);
	ans = min(ans, tans);
	return;
}

int main(){
	int t, i;
	s(t);
	char s1[100000 + 1], s2[100000 + 1];
	set <int>::iterator s1it, s2it;
	set <int>::iterator s1itc, s2itc;

	while (t--){
		scanf("%s", s1);
		scanf("%s", s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		ans = MODULO;
		for (i=0; i<26; i++){
			s1c[i].clear(); s2c[i].clear();
		}
		for (i=0; i<l1; i++){
			s1c[ s1[i] - 65 ].insert(i);
		}
		for (i=0; i<l2; i++){
			s2c[ s2[i] - 65 ].insert(i);
		}
		for (i=0; i<l1; i++){
			s1it = s1c[s1[i] - 65].find(i);
			s2it = s2c[s1[i] - 65].lower_bound(l2/2);
			int it = s1[i] - 65;
			solve(s1it, s2it, it);
			// lr
			if (s2it != s2c[it].end()){
				s1itc = s1it; s2itc = s2it;
				s2itc++; solve(s1itc, s2itc, it);
			}
			if (s2it != s2c[it].begin()){
				s1itc = s1it; s2itc = s2it;
				s2itc--; solve(s1itc, s2itc, it);
			}
			// printf("hi\n");
			// end
			if (s2c[it].size() == 0)
				continue;
			s2itc = --(s2c[it].end()); 
			solve(s1itc, s2itc, it);
			s2itc = s2c[it].begin();
			solve(s1itc, s2itc, it);
		}
		p(ans);
	}

	return 0;
}