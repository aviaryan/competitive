#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
    
    int N,K;
    int i,j;
    long t;
    
    scanf("%d%d",&N,&K);
    long candies[N];

    for(i = 0;i < N;i++)
        scanf("%lu", &candies[i]);

    quicksort(N, candies);

	// calc
    long unfairness=1000000000;
    long t2;

    for(i=0; i<=N-K; i++){
    	t2 = candies[i+K-1] - candies[i];
    	if (t2<unfairness)
    		unfairness = t2;
    }
        
    printf("%lu",unfairness);
    return 0;
}
