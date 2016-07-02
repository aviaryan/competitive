#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

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
	int t, i, m, n;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &m, &n);
		int boys[m], girls[n];

		for (i=0; i<m; i++) scanf("%d", boys+i);
		for (i=0; i<n; i++) scanf("%d", girls+i);

		if (m>n)
			printf("NO\n");
		else {
			quicksort(m, boys); // I should use counting sort, I know
			quicksort(n, girls);
			int suc = 1;
			for (i=0; i<m; i++)
				if (girls[i] >= boys[i]){
					suc = 0;
					break;
				}
			printf("%s\n", suc==0 ? "NO" : "YES");
		}

	}
	return 0;
}