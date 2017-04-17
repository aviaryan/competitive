#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define MODULO 1000000007
#define m(a) ((a)%MODULO)


int main(){
	int n, q, i, x, y, op, j;
	scanf("%d %d", &n, &q);

	// int sar[n+1]; sar[0] = 0;
	ll arr[n+1], p, ps;
	for (i=0; i<=n; i++) arr[i] = 0;

	// for (i=1; i<n; i++)
	// 	sar[i] = (i*(i+1)) + sar[i-1];

	for (i=0; i<q; i++){
		scanf("%d %d %d", &op, &x, &y);

		if (op == 1){
			p = 1;
			for (j = x; j<=y; j++){
				arr[j] += p*(p+1);
				p++;
			}
		} else {
			ps = 0;
			for (j = x; j<=y; j++) ps += arr[j];
			printf("%lld\n", m(ps));
		}

	}
	return 0;
}