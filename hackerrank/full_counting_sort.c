#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long n;
	int i;
	scanf("%ld", &n);
	long nbk = n/2;
	long arr[100] = {0};
	char scol[100][1000][11];

	for (;n>0;n--){
		scanf("%d", &i);
		arr[i]++;
		scanf("%s", &scol[i][ arr[i]-1 ]);
		if (n>nbk){
			scol[i][ arr[i]-1 ][0] = '-';
			scol[i][ arr[i]-1 ][1] = '\0';
		}
	}

	for (i=0; i<100; i++){
		for (n=0; n<arr[i]; n++){
			printf("%s ", scol[i][n] );
		}
	}
}
