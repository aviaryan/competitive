#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int n, i, j, k, end=0;
	unsigned long long m, bts, ts[100000] = {0}, mx;

	for (;t>0;t--){

		scanf("%d %llu", &n, &m);
		end=0, mx=0;
		for (i=0; i<n; i++){
			scanf("%llu", &bts);
			bts %= m;
			if (end==0)
			for (j=0; j<=i; j++){
				ts[j] += bts;
				if (ts[j]%m == (m-1))
					end=1;
				else if (ts[j]%m > mx)
					mx = ts[j];
			}
		}

		if (end==1){
			printf("%llu\n", m-1);
			continue;
		}
		else
			printf("%llu\n", mx);

	}
}
