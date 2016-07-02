#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

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
	int t, i;
	scanf("%d", &t);
	int n,k, min, sdif, cur, pcur, bk;
	int arr[100000], dis[100000];

	for (;t>0;t--){
		sdif = 0;
		scanf("%d %d", &n, &k);
		for (i=0; i<n; i++)
			scanf("%d", arr+i);
		quicksort(n, arr);
		for (i=0; i<(n-1); i++) // the distances
			dis[i] = arr[i+1] - arr[i], sdif += dis[i];
		sdif /= (k-1); // a limit of max distance
		// create groups
		cur = 0;
		min = 1000000000;
		for (i=0; i<(n-1); i++){
			cur += dis[i];
			bk = dis[i];
			dis[i] = 0;
			if (cur>sdif){
				if (pcur!=0)
					i--, cur -= bk;
				dis[i] = cur, cur = 0, pcur = 0;
				if (dis[i] < min)
					min = dis[i];
			} else
				pcur = 1;
		}
		printf("%d\n", min);
	}
	return 0;
}