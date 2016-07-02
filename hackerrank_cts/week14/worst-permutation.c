#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	int i, arr[n], locs[n], bk;

	for (i=0; i<n; i++)
		scanf("%d", arr+i), locs[arr[i]-1] = i;

	for (i=0; i<n; i++){
		if (arr[i] != (n-i)){
			bk = arr[i];
			arr[ locs[n-i-1] ] = bk; // send cur to cornum's location (corect number)
			locs[bk-1] = locs[n-i-1]; // update its location
			arr[i] = n-i; // bring n-i to this location
			locs[n-i-1] = i; // update its pointer
			k--;
			if (k==0)
				break;
		}
	}

	for (i=0; i<n; i++)
		printf("%d ", arr[i]);

	return 0;
}