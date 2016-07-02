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
	int t, i, i2, k, n, j;
	//ios_base::sync_with_stdio(0);
	//cin >> t;
	scanf("%d", &t);
	int heights_count[2501];
	vector <int> v;
	vector <int>::iterator vi;

	for (j=1; j<=t; j++){
		scanf("%d", &n);
		for (i=0; i<2501; i++)
			heights_count[i] = 0;
		for (i=0; i<(2*n - 1); i++){
			for (i2=0; i2<n; i2++){
				scanf("%d", &k);
				heights_count[k]++;
			}
		}
		// loop hc and get the ans
		v.clear();
		for (i=1; i<2501; i++){
			if ( (heights_count[i] > 0) && (heights_count[i]%2 == 1) ){
				v.push_back(i);
			}
		}
		if (v.size() != n){
			printf("error");
		}
		sort(v.begin(), v.end());

		printf("Case #%d: ", j);
		for (vi = v.begin(); vi != v.end(); vi++){
			printf("%d ", *vi);
		}
		printf("\n");

	}

	return 0;
}