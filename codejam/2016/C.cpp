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
	int t, i, n, j, n2, ct, k, i2, k2, lc;
	scanf("%d", &t);
	char secondl1[40];

	for (lc=1; lc<=t; lc++){
		scanf("%d %d", &n, &j);
		n2 = n/2;
		ct = 0;

		printf("Case #%d:\n", lc);
		// first empire
		// for (i=3; i<=(n2-2-1); i++){
		// 	for (k=1; k<i; k++)
		// 		printf("00");
		// 	printf("11");
		// 	for (k=i+1; k<n2; k++)
		// 		printf("00");
		// 	printf("11 ");
		// 	for (k=2; k<=10; k++)
		// 		printf("%d ", k+1);
		// 	printf("\n");
		// 	ct++;
		// 	if (ct == j) break;
		// }

		//printf("first ends");

		// second empire
		for (i=3; i<=(n-2-2-1); i++){ // in 16, 11
			secondl1[0] = '1';
			secondl1[1] = '1';
			for (k=3; k<i; k++){
				secondl1[k-1] = '0';
				//printf("0");
			}
			secondl1[k-1] = '1';
			secondl1[k] = '1';
			secondl1[k+1] = '\0';
			//printf("11");

			// second level
			for (i2=i+2 - 2; i2<=(n-2-1); i2++){ // smart technique
				printf("%s", secondl1);
				for (k2=i+2; k2<i2; k2++)
					printf("0");
				if (i2 >= (i+2))
					printf("11");
				else {
					i2++;
					printf("0");
				}
				for (k2=i2+2; k2<=(n-2); k2++)
					printf("0");
				printf("11 ");
				// print divs
				for (k=2; k<=10; k++)
					printf("%d ", k+1);
				printf("\n");
				ct++;
				if (ct == j) break;
			}
			if (ct == j) break;
		}

		// why in the hell am I bothering
		// printf("\n");
	}

	return 0;
}