#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

main(){
	int n, i;
	scanf("%d", &n);
	char str[n+1];
	int arr[255] = {0};

	scanf("%s", str);

	for (i=0; i<n; i++){
		if ( arr[ (int) str[i] ] == 0 ){
			arr[ (int) str[i] ] = 1;
			printf("%c", str[i]);
		}
	}
}