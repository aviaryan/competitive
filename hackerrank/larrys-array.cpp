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
	int t, i, j, ps, n;
	s(t);
	int arr[1000];

	while (t--){
		s(n);
		for (i=0; i<n; i++)
			s(arr[i]);
		// skip last 2, they are auto
		for (i=0; i<(n-2); i++){
			if (arr[i] == i+1)
				continue;
			// find it
			for (j=i+1; j<n; j++)
				if (arr[j] == i+1)
					break;
			// pull it back
			ps = j;
			while (ps > i){
				if ((ps - i) >= 2){  // 2 3 i => i 2 3
					arr[ps] = arr[ps-1];
					arr[ps-1] = arr[ps-2];
					arr[ps-2] = i+1;
					ps -= 2;
				} else {  // 2 i 3 => i 3 2
					arr[ps] = arr[ps+1];
					arr[ps+1] = arr[ps-1];
					arr[ps-1] = i+1;
					ps -= 1;
				}
			}
		}
		// last 2 should be sorted
		if (arr[n-2] < arr[n-1]){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}