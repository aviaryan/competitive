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
};


int main(){
	int t, j, i, k, sp, cc, n, ans, pk, vib, ppk;

	scanf("%d", &t);
	//struct child bffs[1001];
	int bffs[1001];
	bool visited[1001];
	int useless[10001], uct;
	map <int, int> rfs;

	for (j=1; j<=t; j++){
		scanf("%d", &n);
		rfs.clear();

		for (i=1; i<=n; i++){
			scanf("%d", &k);
			//bffs[i].fs.push_back(k);
			//bffs[k].fs.push_back(i);
			bffs[i] = k;
			rfs.insert( make_pair(k, i) );
			visited[i] = false;
		}

		ans = 0;
		for (i=1; i<=n; i++){
			for (k=1; k<=n; k++) visited[k] = false;

			sp = i;
			visited[sp] = true;
			k = bffs[i];
			cc = 0;
			vib = 0;
			useless[0] = i;
			uct = 0;

			while (k != sp && (useless[uct] == useless[uct-2] || visited[k] == false) ){
				cc++;
				vib = 0;
				if (ppk == k){
					printf("hi");
					vib = 1;
				}
				// if ((cc>1) && rfs.find(sp) != rfs.end()){
				// 	if (*rfs.find(k) == sp){

				// 	}
				// }
				useless[++uct] = k;
				visited[k] = true;
				ppk = pk;
				pk = k;
				printf("%d\n", k);
				k = bffs[k];
			}
			printf("kk %d %d", pk, k);
			if (vib != true)
				if (k != sp) cc = 0;
			printf("ans %d %d", cc, i);
			if (cc > 0 && k == sp){
				cc++;
			} else if (cc > 1 && (visited[k] == true)){
				cc++;
			}
			printf("---\n");
			ans = max(cc, ans);
		}

		printf("Case #%d: %d\n", j, ans);
		//printf("%d\n", t);
	}
	// end loop
}