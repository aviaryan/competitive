#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int halflen;

int quicksort(int ar_size, int *  ar) {
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

  if (c==halflen){  // exit immediately
    return 0;
  }

  if (ar_size>2){
    if (c!=0)
      quicksort(c, &ar[0]);
    if (ar_size-c-1 != 0)
      quicksort(ar_size-c-1, &ar[c+1]);
  }

  return 0;
}


int main() {
  int n,nbk,med;
  scanf("%d", &n);
  halflen = n/2;

  int arr[n];
  for (nbk=0 ;nbk<n; nbk++){
    scanf("%d", &arr[nbk]);
  }

  med = quicksort(n, arr);
  printf("%d", arr[halflen] );
}

