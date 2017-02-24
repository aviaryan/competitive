#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n][n];
	int cpy[n][n];

	int i,j,k,w;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++){
			scanf("%1d", &arr[i][j]);
			cpy[i][j] = arr[i][j];
		}

	for (i=1;i<(n-1); i++)
		for (j=1; j<(n-1); j++){
			w = arr[i][j];
			if ((w>arr[i-1][j]) && (w>arr[i][j-1]) && (w>arr[i][j+1]) && (w>arr[i+1][j])){
				cpy[i][j] = 0;
			}
		}

	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
			printf("%c", cpy[i][j]==0 ? 'X' : (char) cpy[i][j]+48 );
		printf("\n");
	}
}
