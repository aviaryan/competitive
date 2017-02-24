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
	int t, i, n, mat, a, b;
	//ios_base::sync_with_stdio(0);
	s(t);
	vector<int> defs[251];
	bool attendance[251];
	vector<int>::iterator vit, vitt;
	int maxds, curds, temp, maxid;

	while (t--){
		cin >> n;
		mat = (n * (n-1)) /2;
		for (i=1; i<=n; i++)
			defs[i].clear();
		for (i=0; i<mat; i++){
			scanf("%d %d", &a, &b);
			defs[a].push_back(b);
		}

		maxds = 0;
		for (i=1; i<=n; i++){
			fill_n(attendance, n+1, false);
			curds = 0;
			for (vit = defs[i].begin(); vit != defs[i].end(); vit++){
				if (!(attendance[*vit])){
					curds++;
					temp = *vit;
					attendance[temp] = true;
					for (vitt = defs[temp].begin(); vitt != defs[temp].end(); vitt++){
						if (!(attendance[*vitt])){
							curds++;
							attendance[*vitt] = true;
						}
					}
				}
			}
			if (curds > maxds){
				maxid = i; maxds = curds;
			}
		}

		printf("%d %d\n", maxid, maxds);
	}

	return 0;
}