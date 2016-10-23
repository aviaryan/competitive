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
	int t, i, n;
	bool suc;
	s(t);
	int arr[2 * 100000];

	while (t--){
		s(n);
		for (i=0; i<n; i++)
			s(arr[i]);
		sort(arr, arr+n);
		suc = true;
		for (i=1; i<n; i++){
			if (abs(arr[i] - arr[i-1]) > 1){
				suc = false;
				break;
			}
		}
		if (suc)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}