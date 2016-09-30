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
	s(n);
	int arr[n];

	for (i=0; i<n; i++) 
		scanf("%d", &arr[i]);

	int ans=0;
	for (i=1; i<n; i++){
		if (arr[i-1] % 2 == 1){
			arr[i-1] ++;
			arr[i] ++;
			ans ++;
		}
	}

	if (arr[n-1] % 2 == 1){
		printf("NO\n");
	} else {
		printf("%d\n", ans*2);
	}
	return 0;
}