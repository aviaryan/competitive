#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long qc=0,ic=0;

void quicksort(int ar_size, int *  ar) {
  int piv;
  piv = ar[ar_size-1];
  int i, temp, c=0;
  int prevmax, prevind=-1; //a/c ques

  for (i=0; i<ar_size-1; i++){
    if (ar[i] < piv){
      if ((prevind>-1) && (ar[i] < prevmax)){
        temp = ar[i];
        ar[i] = prevmax;
        ar[ prevind ] = temp;
        prevind = prevind+1;
        prevmax = ar[prevind];
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

  if (ar_size>2){
    if (c!=0)
      quicksort(c, &ar[0]);
    if (ar_size-c-1 != 0)
      quicksort(ar_size-c-1, &ar[c+1]);
  }
}

void insertionSort(int ar_size, int *  ar) {
	int k;
	int i, i0, s;

	for (i0=2; i0<=ar_size; i0++){
		k = ar[i0-1], s=0;

		for (i=i0-2; i>-1; i--){
			if (ar[i] >= k){
				ar[i+1] = ar[i];
				ic++; // shift
			}
			else if (ar[i] < k){
				ar[i+1] = k;
				s = 1;
				break;
			}
		}
		if (s==0)
			ar[0] = k;
	}
	
}

int main() {
	int k;
	scanf("%d", &k);
	int arr[k], acpy[k];
	int i;

	for (i=0; i<k; i++){
		scanf("%d", &arr[i]);
		acpy[i] = arr[i];
	}

	quicksort(k, arr);
	insertionSort(k, acpy);

	printf("%d-%d", qc, ic);

}
