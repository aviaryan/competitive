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
	int t, i, n, m, mb;
	s(t);
	int arr[2 * 10000];
	int c;

	while (t--){
		scanf("%d %d", &n, &m);
		for (i=0; i<m; i++)
			scanf("%d", arr+i);
		sort( arr, arr+m );
		c = 0;
		mb = m-1;

		for (i=0; i<m; i++){
			while (c < mb){
				c++;
				if (arr[i] == 1){
					mb--;
					break;
				} else
					arr[i]--;
			}
		}

		p(c);
	}


	return 0;
}