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

// http://tech-lightnight.blogspot.in/2012/11/distinct-subsequences.html

int countSubs(string S, string T) {
    vector<int> w(S.size()+1, 0);
    vector<vector<int> > v(T.size()+1, w);
    int maxS = S.size()-1;
    int maxT = T.size()-1;
    for(int ii = 0; ii < S.size(); ++ii){
        if (T[maxT] == S[ii]) v[maxT][ii] = 1;
    }
    for(int ss = maxS-1; ss>=0; --ss){
        for(int tt = maxT; tt >= 0; --tt){
            v[tt][ss] += v[tt][ss+1];
            if (T[tt] == S[ss]) v[tt][ss] += v[tt+1][ss+1] ;               
        }
    }
    return v[0][0];
}

int main(){
	int t, i;
	// char s1[100000], s2[100000];
	ios_base::sync_with_stdio(0);
	string s1, s2;
	cin >> s1 >> s2;
	p(countSubs(s2, s1));

	return 0;
}