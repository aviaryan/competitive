#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// quicksort fails - simple method fails
#define NL 1000000
long rec[NL+1];


int main() {
	int t;
	scanf("%d", &t);
	int n, i, j;
	long long ans;

	for (;t>0;t--){
		scanf("%d", &n);

		for (i=1; i<=NL; i++) rec[i] = 0;

		for (i=0; i<n; i++){
			scanf("%d", &j);
			rec[j]++;
		}

		ans = 0;
		for (i=1; i<=NL; i++)
			if (rec[i]>1)
				ans += ((rec[i] * (rec[i]-1)));

		printf("%lld\n", ans);
	}

    return 0;
}
