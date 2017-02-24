#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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


int main() {
	int n;
	scanf("%d", &n);
	int k, arr[n];
	for (k=0;k<n;k++)
		scanf("%d", arr+k);
	quicksort(n, arr);
	int min = 100000000; //10^8

	for (k=0; k<(n-1); k++){
		if ( (arr[k+1] - arr[k]) < min )
			min = arr[k+1] - arr[k];
	}

	for (k=0; k<(n-1); k++){
		if ( (arr[k+1] - arr[k]) == min )
			printf("%d %d ", arr[k], arr[k+1]);
	}

    return 0;
}
