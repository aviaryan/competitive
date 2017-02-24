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
	int t;
	int n, i, j, sp, usp;
	scanf("%d", &t);
	int arr[100000], cpy[100000];
	unsigned long long ans, tans;

	for (;t>0;t--){
		scanf("%d", &n);
		for (i=0; i<n; i++){
			scanf("%d", arr+i);
			cpy[i] = arr[i];
		}

		quicksort(n, arr);
		ans = 0;
		for (i=0; i<n; i++){
			sp = arr[i];
			tans = 0;
			for (j=0; j<n; j++)
				if ( sp == cpy[j] ){
					cpy[j] = 0;
					ans += tans;
					break;
				}
				else
					if (j>=i)
						tans++;
		}

		printf("%llu\n", ans);
	}

	return 0;

}
