#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, m, i, k, min=10001;
	int a[10001] = {0};
	int b[10001] = {0};

	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%d", &k);
		a[k]++;
	}

	scanf("%d", &m);
	for (i=0; i<m; i++){
		scanf("%d", &k);
		if (k<min)
			min = k;
		b[k]++;
	}
	// print missing numbers

	for (i=min; i<=(min+101); i++)
		if ( (b[i] - a[i]) > 0 )
			printf("%d ", i);

	return 0;
}
