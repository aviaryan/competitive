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
	s(t);
	bool suc;
	int arr[100000];

	while (t--){
		s(n);
		suc = false;
		for (i=0; i<n; i++){
			s(arr[i]);
		}
		for (i=1; i<(n-1); i++){
			if (arr[i-1] == arr[i] && arr[i] == arr[i+1]){
				suc = true;
				break;
			}
		}
		if (suc){
			printf("Yes\n");
		} else
			printf("No\n");
	}

	return 0;
}