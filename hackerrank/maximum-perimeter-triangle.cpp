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
	int t, i, j, k, n;
	s(n);
	int arr[n];
	for (i=0; i<n; i++){
		s(arr[i]);
	}
	sort(arr, arr+n);
	// solve
	bool done = false;
	for (i=n-1; i>=2; i--){
		for (j=i-1; j>=1; j--){
			for (k=j-1; k>=0; k--){
				if ( (arr[i] + arr[j] <= arr[k])
					|| (arr[j] + arr[k] <= arr[i])
					|| (arr[i] + arr[k] <= arr[j]) )
					continue;
				done = true;
				break;
			}
			if (done) break;
		}
		if (done) break;
	}

	if (!done)
		printf("-1\n");
	else
		printf("%d %d %d", arr[k], arr[j], arr[i]);
	return 0;
}