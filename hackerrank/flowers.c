/* Sample program illustrating input/output methods */
#include<stdio.h>

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


int main(){

   int i, n, k;
   int c[102];
   
   scanf("%d %d", &n, &k);
   for(i=0; i<n; i++){
      scanf("%d", &(c[i]));
   }
   
   quicksort(n, &c[0]);
   int result = 0, times=0, j=k;

   for (i=n-1; i>=0; i--){
   		j--; // a friend buys
   		result += (times+1) * c[i];
   		if (j==0){
   			j=k;
   			times++;
   		}
   }

   printf("%d\n", result);
}
