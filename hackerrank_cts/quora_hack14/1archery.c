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
	unsigned long qs=0, t, t2, swap;
	scanf("%d", &n);
	int rads[n], i,j,k;
	for (i=0; i<n; i++)
		scanf("%d", &rads[i]); // assume rads are aligned
	quicksort(n, &rads[0]);
	int m,c1,c2;
	scanf("%d", &m);
	int x1,x2,y1,y2;
	for (i=0; i<m; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		t = sqrt( x1*x1 + y1*y1 );
		t2 = sqrt( x2*x2 + y2*y2 );
		if (t>t2){
			swap = t;
			t = t2;
			t2 = swap;
		}

		c1 = 0;
		for (j=0; j<n; j++){
			if ( rads[j] > t ){ah
				break;
			}
		}
		c1 = j; // if the whole thing not breaks j is already incremented

		c2 = 0; // take that incremented j
		for (j=c1; j<n; j++){
			if ( rads[j] > t2 )
				break;
			c2++;
		}

		qs += c2;
	}
	printf("%lu", qs);
}
