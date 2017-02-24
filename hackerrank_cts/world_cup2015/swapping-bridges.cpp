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
	int t, i, n, j, c;
	//ios_base::sync_with_stdio(0);
	s(t);
	int con[50000+1];
	bool attend[50000+1];

	while (t--){
		s(n);
		c = 0;
		fill_n(attend, n+1, 0);
		for (i=1; i<=n; i++){
			s(j);
			con[i] = j;
		}
		for (i=1; i<=n; i++){
			if (!attend[i]){
				attend[i] = 1;
				j = con[i];
				while (j != i){
					attend[j] = 1;
					j = con[j];
				}
				c++;
			}
		}
		printf("%d\n", c-1);
	}

	return 0;
}