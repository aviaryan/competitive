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
	int t, i, n, j, ct, k;
	s(t);
	int arr[100000];

	while (t--){
		scanf("%d %d", &n, &k);
		if (k == 0){
			for (i=1; i<=n; i++)
				printf("%d ", i);
		} else if (n % (2*k) != 0){
			printf("-1");
		} else {
			j = n / (2*k);
			ct = 0;
			while (j--){	
				for (i=ct; i<(ct+k); i++){
					arr[i] = i + 1 + k;
				}
				for (i=ct+k; i<(ct+2*k); i++){
					arr[i] = i - k + 1;
				}
				ct += 2*k;
			}
			// print
			for (i=0; i<n; i++)
				printf("%d ", arr[i]);
		}
		printf("\n");
	}

	return 0;
}