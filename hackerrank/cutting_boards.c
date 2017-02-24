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

/*
MNNNNNNNN
M
M
verical cuts - xn
horizontal - ym
*/

int main() {
	long long t,i,j;
	scanf("%lld", &t);
	long long m,n;
	int mc[100000], nc[100000];
  long long mcost, ncost, cost, ml, nl, xdiv, ydiv;
	
	for (;t>0;t--){

		scanf("%lld %lld", &m, &n);
		xdiv = 1, ydiv = 1, cost=0;
		for (i=0; i<(m-1); i++)
			scanf("%d", &mc[i]);
		for (i=0; i<(n-1); i++)
			scanf("%d", &nc[i]);
		quicksort(m-1, mc);
		quicksort(n-1, nc);

		for (i=0; i<(n+m-2); i++){ // all total cuts
			ml = mc[ m-1-ydiv ];
			nl = nc[ n-1-xdiv ]; // the max lines to cut
			mcost = ml * xdiv;
      ncost = nl * ydiv;

      if (ml > nl){
        cost += mcost;
        ydiv++;
      } else if ( nl > ml ){
        cost += ncost;
        xdiv++;
      } else {
        if ( mcost > ncost ){
          cost += mcost;
          ydiv++;
        }
        else {
          cost += ncost;
          xdiv++;
        }
      }

		}

    printf("%lld\n", cost % 1000000007);

	}

}
