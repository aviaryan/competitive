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
	int t, i, i2, i3, j, k, p, s, j2;
	//ios_base::sync_with_stdio(0);
	//cin >> t;
	scanf("%d", &t);
	int jp[10][10];
	int ps[10][10];
	int js[10][10];
	bool jps[10][10][10];

	for (j2=1; j2<=t; j2++){
		scanf("%d %d %d %d", &j, &p, &s, &k);

		for (i=0; i<j; i++) for(i2=0; i2<p; i2++) jp[i][i2] = 0;
		for (i=0; i<p; i++) for(i2=0; i2<s; i2++) ps[i][i2] = 0;
		for (i=0; i<j; i++) for(i2=0; i2<s; i2++) js[i][i2] = 0;
		for (i=0; i<j; i++) for(i2=0; i2<p; i2++) for(i3=0; i3<s; i3++) jps[i][i2][i3] = false;

		int ans=0;	
		for (i=0; i<j; i++){
			for (i2 = 0; i2<p; i2++){
				for (i3 = 0; i3<s; i3++){
					if ((jps[i][i2][i3] == false) && (jp[i][i2] != k) && (ps[i2][i3] != k) && (js[i][i3] != k)){
						ans++;
						jp[i][i2]++; ps[i2][i3]++; js[i][i3]++;
						jps[i][i2][i3] = true;
					}
				}
			}
		}

		printf("Case #%d: %d\n", j2, ans);
		for (i=0; i<j; i++){
			for (i2 = 0; i2<p; i2++){
				for (i3 = 0; i3<s; i3++){
					if (jps[i][i2][i3] == false) continue;
					printf("%d %d %d\n", i+1, i2+1, i3+1);
				}
			}
		}
		// end
	}

	return 0;
}