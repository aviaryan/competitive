#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef set<int> si;
typedef set<int>::iterator siit;

int *alps[201];
si * sarr[201]; // m limited to 200
int arr[200000];

int main(){
	int t, m, k, n, i, x, y;
	cin >> t;

	int ct;

	while (t--){
		scanf("%d %d %d", &m, &k, &n);
		for (i=1; i<=m; i++)
			alps[i] = NULL, sarr[i] = NULL;
		ct = 1;

		for (i=0; i<k; i++){
			scanf("%d %d", &x, &y);
			if (x>y) swap(x,y);

			if (alps[x] != NULL){
				if (alps[y] == NULL)
					alps[y] = alps[x];
				else
					*alps[y] = *alps[x];
			} else if (alps[y] != NULL)
				alps[x] = alps[y];
			else {
				int z = ct++;
				alps[x] = &z;
				alps[y] = &z;
			}
		}

		for (i=1; i<=m; i++){
			if (alps[i] == NULL){
				int z = ct++;
				alps[i] = &z;
			}
			if ( sarr[*alps[i]] != NULL){
				sarr[*alps[i]]->insert(i);
			} else {
				si * theset = new si; //.clear();
				theset->insert(i);
				sarr[ *alps[i] ] = theset;
			}
		}

		for (i=0; i<n; i++) scanf("%d", &arr[i]);


	}

	return 0;
}