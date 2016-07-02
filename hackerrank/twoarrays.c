#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TEN9 10000 //question asked 10^9 but this too worked

void quicksort(long ar_size, long *  ar) {
  long piv;
  piv = ar[ar_size-1];
  long i, temp, c=0;
  long prevmax, prevind=-1; //a/c ques

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
	int t;
	scanf("%d", &t);
	int n,i,j,s;
	long k, a[TEN9], b[TEN9];

	for (;t>0;t--){
		scanf("%d %ld", &n, &k);
		for (i=0; i<n; i++)
			scanf("%ld", &a[i]);
		for (i=0; i<n; i++)
			scanf("%ld", &b[i]);
		quicksort(n,&a[0]);
		quicksort(n,&b[0]);
		s = 1;
		for (i=0; i<n; i++){
			if ( ( a[i] + b[n-i-1] ) < k ){
				s = 0;
				break;
			}
		}
		printf("%s\n", s==1 ? "YES" : "NO");
	}
}
