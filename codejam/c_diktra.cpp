#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

ifstream fin("C-small-attempt0.in");
ofstream fout("output.txt");


int n,x,twor;
char str[10001];
pii prods_backs[10000];
int rls[4][4];
pii fulls;


int lookfor(int ind, int svalue, int ss, int search, int * lastv, int * lasts){
	int c = ind/n;
	ind = ind%n;
	int s=ss, p=0, i;
	int sn = search<0 ? 1 : 0;

	while (c < x){
		for (i=ind; i<n; i++){
			svalue = rls[svalue][str[i]];
			if (svalue <= 0){
				s = (s)?0:1;
				svalue = -svalue;
			}
			if (svalue == search)
				if (sn == s){
					*lastv = svalue;
					*lasts = s;
					return (c*n) + i;
				}
		}
		c++;
		ind = 0;
	}
	return -1;
}

int iskp(int ind){
	int c = ind/n, i;
	ind = ind%n;
	int s=0, p=0;
	// for (i=ind; i<n; i++){
	// 	p = rls[p][str[i]];
	// 	if (p<=0){
	// 		s = (s)?0:1;
	// 		p = -p;
	// 	}
	// }
	s = prods_backs[ind].first;
	p = prods_backs[ind].second;
	c++;
	// use twor
	int times = (x-c)/2;
	int rem = (x-c)%2;
	int k = pow( twor, times );
	if (k == -1)
		s = s?0:1;
	while (rem--){
		p = rls[p][fulls.second];
		if (fulls.first)
			s = (s)?0:1;
		if (p<=0){
			s = (s)?0:1;
			p = -p;
		}
	}
	// while (c<x){
	// 	p = rls[p][fulls.second];
	// 	if (fulls.first)
	// 		s = (s)?0:1;
	// 	if (p<=0){
	// 		s = (s)?0:1;
	// 		p = -p;
	// 	}
	// 	c++;
	// }
	if (s==0 && (p==3))
		return 1;
	else
		return 0;
}

int solve(){
	int lasti=-1, lastiv=0, lasts=0;
	int lastj, lastjv, lastjs, s=0;

	while (1){
		lasti = lookfor(lasti+1, lastiv, lasts, 1, &lastiv, &lasts);
		if (lasti == -1)
			return 0;

		lastj = lasti, lastjv=0, lastjs=0;
		while (1) {
			lastj = lookfor(lastj+1, lastjv, lastjs, 2, &lastjv, &lastjs);
			if (lastj == -1)
				break;
			else
				if (iskp(lastj+1))
					return 1;
		}
	}

}

int main(){
	int t, i, j;
	fin >> t;
	int p,s,kcame;
	rls[0][1] = 1, rls[0][2] = 2, rls[0][3] = 3;
	rls[1][0] = 1, rls[1][1] = 0, rls[1][2] = 3, rls[1][3] = -2;
	rls[2][0] = 2, rls[2][1] = -3, rls[2][2] = 0, rls[2][3] = 1;
	rls[3][0] = 3, rls[3][1] = 2, rls[3][2] = -1, rls[3][3] = 0;


	for (j=1; j<=t; j++) {
		fin >> n >> x;
		fin >> str;
		p=0; s=0;
		kcame = 0;
		for (i=0; i<n; i++){
			if (str[i] == 'i') str[i] = 1;
			else if (str[i] == 'j') str[i] = 2;
			else str[i] = 3;
			p = rls[p][str[i]];
			if (p<=0){
				s=(s)?0:1;
				p = -p;
			}
		}
		// sign 1 for negative
		twor = p==0 ? 1 : -1;
		fulls = make_pair(s, p);

		p=0;s=0;
		for (i=n-1; i>=0; i--){
			p = rls[str[i]][p];
			if (p<=0){
				s=(s)?0:1;
				p = -p;
			}
			if (p==3) kcame = 1;
			prods_backs[i] = make_pair(s,p);
		}

		cout << "Case #" << j << ": " << (kcame==0 ? "NO" : (solve() ? "YES" : "NO")) << endl;
	}

	return 0;
}