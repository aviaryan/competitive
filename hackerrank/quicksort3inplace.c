#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int *iptr, arrsz;

void printarr(){
	int *ar2, i;
	ar2 = iptr;
	for (i=0; i<arrsz; i++)
		printf("%d ", ar2[i]);
	printf("\n");

}

void quicksort(int ar_size, int *  ar) {
	int piv;
	piv = ar[ar_size-1];
	int i, j, temp, c=0, d=0;
	int prevmax, prevind=-1; //a/c ques

	for (i=0; i<ar_size-1; i++){
		if (ar[i] < piv){
			if ((prevind>-1) && (ar[i] < prevmax)){
				temp = ar[i];
				ar[i] = prevmax;
				ar[ prevind ] = temp;
				prevind = prevind+1;
				prevmax = ar[prevind];
				d++;
			}
			c++;
		}
		else if (prevind<0) {
			prevmax = ar[i];
			prevind = i;
		}
	}

	if (prevind>-1){
		ar[ar_size-1] = ar[c];
		ar[c] = piv;
	}

	if ((prevind>-1) || (c>0))
		printarr();

	if (ar_size>2){
		if (c!=0)
			quicksort(c, &ar[0]);
		if (ar_size-c-1 != 0)
			quicksort(ar_size-c-1, &ar[c+1]);
	}
}


int main(void) {
   
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]); 
	}
	
	iptr = &_ar[0];
	arrsz = _ar_size;
	quicksort(_ar_size, _ar);

	return 0;
}