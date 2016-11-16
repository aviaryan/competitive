#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%lld", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	ll t, i, n, j;
	s(n);
	ll arr[n];

	ll tsum = 0;
	for (i=0; i<n; i++){
		s(arr[i]);
		tsum += arr[i];
	}

	ll sum = 0, fsum;
	for (i=0; i<n; i++){
		sum += arr[i];
		if (tsum % sum == 0){
			// check
			fsum = 0;
			for (j=i+1; j<n; j++){
				fsum += arr[j];
				if (fsum > sum) 
					break;
				if (fsum == sum) 
					fsum = 0;
			}
			if (fsum == 0 && j == n){
				printf("%lld %lld\n", sum, tsum / sum);
			}
		}
	}

	return 0;
}