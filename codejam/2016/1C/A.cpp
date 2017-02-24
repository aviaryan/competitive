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
	int t, i, j, mx, mx_i, n, n2, tot;
	int arr[36];
	//ios_base::sync_with_stdio(0);
	scanf("%d", &t);

	for (j=1; j<=t; j++){
		scanf("%d", &n);
		tot = 0;
		for (i=0; i<n; i++){
			scanf("%d", arr+i);
			tot += arr[i];
		}

		n2 = tot;
		//printf("%d %d", tot, arr[0]);
		printf("Case #%d: ", j);

		while (n2 > 0){
			// first
			mx = arr[0]; mx_i = 0;
			for (i=1; i<n; i++){
				if (arr[i] > mx){
					mx = arr[i];
					mx_i = i;
				}
			}
			arr[mx_i]--;
			n2--;
			printf("%c", (char) 65+mx_i);
			// second
			if (n2 == 2){
				printf(" ");
				continue;
			}
			mx = arr[0]; mx_i = 0;
			for (i=1; i<n; i++){
				if (arr[i] > mx){
					mx = arr[i];
					mx_i = i;
				}
			}
			arr[mx_i]--;
			n2--;
			printf("%c ", (char) 65+mx_i);
		}
		printf("\n");

	}
	return 0;
}