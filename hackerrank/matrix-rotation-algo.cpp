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
	int t, i, n, m, r, j;
	s(m); s(n); s(r);

	int arr[m][n];

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	int sz = min(n, m) / 2;
	int nb = n, mb = m, length, rots, temp;
	int is = 0, ie = m-1, js = 0, je = n-1;
	deque <int> v;
	deque <int>::iterator vi;

	while (sz--){
		length = 2*nb + 2*mb - 4;
		rots = r % length;

		v.clear();
		// journey
		for (i = is; i <= ie; i++){
			v.push_back(arr[i][js]);
		}
		for (j = js+1; j<=je; j++){
			v.push_back(arr[ie][j]);
		}
		for (i = ie-1; i>=is; i--){
			v.push_back(arr[i][je]);
		}
		for (j = je-1; j>js; j--){
			v.push_back(arr[is][j]);
		}
		// reorder
		while (rots--){
			temp = v.back();
			v.pop_back();
			v.push_front(temp);
		}

		vi = v.begin();
		// journey update
		for (i = is; i <= ie; i++){
			arr[i][js] = *vi;
			vi++;
		}
		for (j = js+1; j<=je; j++){
			arr[ie][j] = *vi;
			vi++;
		}
		for (i = ie-1; i>=is; i--){
			arr[i][je] = *vi;
			vi++;
		}
		for (j = je-1; j>js; j--){
			arr[is][j] = *vi;
			vi++;
		}

		is++; ie--; js++; je--;
		nb -= 2; mb -= 2;
	}

	// print rotated
	for (i=0; i<m; i++){
		for (j=0; j<n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	return 0;
}