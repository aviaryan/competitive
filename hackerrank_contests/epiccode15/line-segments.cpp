#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


void quicksort(int ar_size, int *  ar, pair<int,int> * pts) {
  pair<int, int> p_temp, p_prevmax, p_piv; //xxxxxxxx
  int piv;
  piv = ar[ar_size-1];
  p_piv = pts[ar_size-1];
  int i, temp, c=0;
  int prevmax, prevind=-1; //a/c ques

  for (i=0; i<ar_size-1; i++){
    if (ar[i] < piv){
      if ((prevind>-1) && (ar[i] < prevmax)){
        temp = ar[i];
        p_temp = pts[i]; //xxxxxxxxx
        ar[i] = prevmax;
        pts[i] = p_prevmax; //xxxxxxxxx
        ar[ prevind ] = temp;
        pts[ prevind ] = p_temp; //xxxxxxxx
        prevind = prevind+1;
        prevmax = ar[prevind];
        p_prevmax = pts[prevind]; //xxxxxxxxx
      }
      c++;
    }
    else if (prevind<0) {
      prevmax = ar[i];
      p_prevmax = pts[i]; //xxxxxxxxxx
      prevind = i;
    }
  }

  if (prevind>-1){
    ar[ar_size-1] = ar[c];
    pts[ar_size-1] = pts[c]; //xxxxxxxxxxx
    ar[c] = piv;
    pts[c] = p_piv; //xxxxxxxxxxxx
  }

  if (ar_size>2){
    if (c!=0)
      quicksort(c, &ar[0], &pts[0]);
    if (ar_size-c-1 != 0)
      quicksort(ar_size-c-1, &ar[c+1], &pts[c+1]);
  }
}


int main(){
	int n, i, x, y, j;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];
	pair <int,int> pts[n];

	for (i=0; i<n; i++){
		cin >> x >> y;
		arr[i] = y-x;
		pts[i] = make_pair(x, y);
	}

	quicksort(n, arr, pts);

	int x1, y1, n2 = 0, dp, c;

	for (i = n-1; i>0 ; i--){
		x1 = pts[i].first ; y1 = pts[i].second;
		c = 0;
		if (x1==0)
			continue;
		for (j=0; j<i; j++){
			if (pts[j].first >= x1) // 0 wont match this case :-)
				if (pts[j].second <= y1){
					dp = j;
					c++;
					if (c>1)
						break;
				}
		}
		if (c>0){
			n2++;
			if (c==1) pts[dp].first = 0;
		}
	}

	cout << n-n2 << endl;

	return 0;
}