#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void quicksort(int ar_size, int *  ar) {
	int piv;
	piv = ar[0];
	int i, j, temp, c=0;

	for (i=1; i<ar_size; i++){
		if (ar[i] < piv){
			for (j=0; j<i-c; j++){
				temp = ar[i-j-1];
				ar[i-j-1] = ar[i-j];
				ar[i-j] = temp;
			}
			c++;
		}
	}

	if (ar_size>2){

	quicksort(c, &ar[0]);
	quicksort(ar_size-c-1, &ar[c+1]);

	}
	

	if (ar_size > 1){
		for (i=0; i<ar_size; i++)
			printf("%d ", ar[i]);
		printf("\n");
	}
}


int main(void) {
   
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]); 
	}
	
	quicksort(_ar_size, _ar);
	

	return 0;
}
