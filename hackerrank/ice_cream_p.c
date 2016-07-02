#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int arr[10000];
	
	int i,n,m, j, k, s, d;
	for (i=0; i<t; i++){
		scanf("%d%d", &m, &n);
		d = 0;

		for (j=0; j<n; j++)
			scanf("%d", &arr[j]);

		for (j=0; j<n-1; j++){
			for (k=j+1; k<n; k++){
				s = arr[j] + arr[k];
				if (s==m){
					d = 1;
					break;
				}
			}
			if (d==1)
				break;
		}
		printf("%d %d\n", j+1, k+1);
	}
    return 0;
}
