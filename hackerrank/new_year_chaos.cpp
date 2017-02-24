#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int invs;

/**
 * Performs Merge Operation
 * @param sorted sorted array pointer
 * @param arr    original array pointer
 * @param start  array index to start from
 * @param end    array index to end at
 */
void mergeOp(int * sorted, int * arr, int start, int end){
	if (start >= end)
		return;
	int mid = (start+end)/2;
	mergeOp(sorted, arr, start, mid);
	mergeOp(sorted, arr, mid+1, end);
	// actual merging
	int i1 = start, i2 = mid+1, i;
	for (i=start; i<=end && i1<=mid && i2<=end; i++){
		if (sorted[i1] <= sorted[i2]){
			arr[i] = sorted[i1];
			i1++;
		} else {
			arr[i] = sorted[i2];
			i2++;
			invs += (mid - i1 + 1); // magic
		}
	}
	// add remaining
	i1 = (i1 > mid) ? i2 : i1;
	while (i <= end){
		arr[i] = sorted[i1];
		i++; i1++;
	}
	// copy back
	for (i=start; i<=end; i++){
		sorted[i] = arr[i];
	}
}

/**
 * Performs Merge Sort over array
 * @param sorted pointer of sorted array
 * @param arr    pointer of real array
 * @param size   size of array
 */
void mergeSort(int * sorted, int * arr, int size){
	for (int i=0; i<size; i++) sorted[i] = arr[i];
	mergeOp(sorted, arr, 0, size-1);
}



int main(){
	int t, i, n;
	s(t);
	int arr[100000], sorted[100000];
	int ans;

	while (t--){
		s(n);
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		// solve
		ans = 0;
		for (i=0; i<n; i++){
			if ((arr[i] - i - 1) > 2){
				ans = -1;
				break;
			}
		}
		if (ans == 0){
			invs = 0;
			mergeSort(sorted, arr, n);
			printf("%d\n", invs);
		} else {
			printf("Too chaotic\n");
		}
	}

	return 0;
}