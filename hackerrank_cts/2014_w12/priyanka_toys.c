#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(long long ar_size, long long *  ar) {
  long long piv;
  piv = ar[ar_size-1];
  long long i, temp, c=0;
  long long prevmax, prevind=-1; //a/c ques

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
	unsigned long long k,i,w,c=0,j;
	scanf("%llu", &k);
	unsigned long long arr[k];

	for (i=0; i<k; i++)
		scanf("%llu", arr+i);
	
	quicksort(k, &arr[0]);

	for (i=0; i<k; i++){
		w = arr[i];
		for (j=i+1; j<k; j++){
			if (arr[j] > w+4)
				break;
		}
		i = j-1;
		c++;
	}

	printf("%llu", c);
	return 0;
}
