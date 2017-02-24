#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int m,n;

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

unsigned long long mincuts(int xdiv, int ydiv, int *ar_mc, int *ar_nc){
  unsigned long long hzcut, vercut, lower=0;

  if ( m>ydiv )
    hzcut = ( xdiv * ar_mc[m-1-ydiv] ) + mincuts(xdiv, ydiv+1, ar_mc, ar_nc) , lower = hzcut;
  if ( n>xdiv ){
    vercut = ( ydiv * ar_nc[n-1-xdiv] ) + mincuts(xdiv+1, ydiv, ar_mc, ar_nc);
    if (lower == 0)
      lower = vercut;
    else if (vercut < lower)
      lower = vercut;
  }

  return lower;
}

/*
MNNNNNNNN
M
M
verical cuts - xn
horizontal - ym
*/

int main() {
  int t,i,j;
  scanf("%d", &t);
  int ydiv,xdiv;
  int mc[100000], nc[100000], ml, nl;
  unsigned long long mcost, ncost, cost;
  
  for (;t>0;t--){

    scanf("%d %d", &m, &n);
    xdiv = 1, ydiv = 1, cost=0;
    for (i=0; i<(m-1); i++)
      scanf("%d", &mc[i]);
    for (i=0; i<(n-1); i++)
      scanf("%d", &nc[i]);
    quicksort(m-1, mc);
    quicksort(n-1, nc);

    cost = mincuts(1, 1, mc, nc);

    printf("%llu\n", cost);

  }

}