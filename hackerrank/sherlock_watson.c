#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,k,q;
	scanf("%d %d %d", &n, &k, &q);
	int i, j, pos, arr[n], arbk[n];
	for (i=0; i<n; i++){
		scanf("%d", arr+i);
		arbk[i] = arr[i];
	}
	// process - move it rightways
	pos = (k+0)%n;
	arbk[pos] = arr[0];
	for (j=1; j<n; j++){
		pos++;
		if (pos==n)
			pos = 0;
		arbk[pos] = arr[j];
	}
	
	// get and print
	for (i=0; i<q; i++){
		scanf("%d", &pos); //reuse
		printf("%d\n", arbk[pos]);
	}
}
