#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n;
	int i,j;
	cin >> n;
	int arr[n+1];
	for (i=1; i<=n; i++) scanf("%d", &arr[i]);
	arr[0] = MODULO;
	ull maxp=0,l=0,r=0;

	for (i=1; i<=n; i++){
		if (!(arr[i-1] <= arr[i] && l==0)){
			l=0;
			for (j=i-1; j>=1; j--){
				if (arr[j] > arr[i]){
					l = j;
					break;
				}
			}
		}
		if (!(arr[i-1] <= arr[i] && r==0)){
			r=0;
			for (j=i+1; j<=n; j++){
				if (arr[j] > arr[i]){
					r = j;
					break;
				}
			}
		}
		if (l*r > maxp) maxp = l*r;
	}

	cout << maxp;
	return 0;
}