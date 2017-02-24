#include <stdio.h>

main(){
	int n, i, t, j, h;
	scanf("%d", &n);

	int arr[n];
	for (i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	for (i=0; i<n; i++){
		t = arr[i];
		h = 1;
		// g cycles cal
		for (j=0; j<t; j++){
			if (j%2 == 0){
				h = h*2;
			}
			else 
				h = h + 1;
		}
		printf("%d", h);
		printf("\n");
	}
}