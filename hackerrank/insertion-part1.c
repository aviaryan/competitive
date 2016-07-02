#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void printarr(int ar_size, int * ar){
	int i;
	for(i = 0; i < ar_size; i++)
		printf("%d ", ar[i]);
	printf("\n");
}

void insertionSort(int ar_size, int *  ar) {
	int k = ar[ar_size-1];
	int i, s=0;
	for (i=ar_size-2; i>-1; i--){
		if (ar[i] >= k)
			ar[i+1] = ar[i];
		else if (ar[i] < k){
			ar[i+1] = k;
			s = 1;
			printarr(ar_size, &ar[0]);
			break;
		}
		printarr(ar_size, &ar[0]);
	}

	if (s==0){
		ar[0] = k;
		printarr(ar_size, &ar[0]);
	}
}


int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

insertionSort(_ar_size, _ar);
  
   return 0;
}
