#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int arr[2001];
int minsofar, k;

void knapsack_supersum(int breach, int sp){
	int i;
	if (breach<0) // if arrays sum is already more than k
		return;
	if (breach < minsofar)
		minsofar = breach;

	for (i=sp; i>0; i--){
		if (arr[i] == 1)
			knapsack_supersum(breach - i, i-1);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	int n, suc=0, temp, in, i;

	for (;t>0;t--){
		scanf("%d %d", &n, &k);
		suc = 0;

		for (i=0; i<=2000; i++) // empty all attendance
			arr[i] = 0;

		for (i=0; i<n; i++){

			scanf("%d", &in);
			arr[in] = 1;
			if (k % in == 0)
				suc = 1;
			else { // add attendance to all multiples of the number
				temp = in*2;
				while (temp<=k){
					arr[temp] = 1;
					temp += in;
				}
			}

		}

		if (suc == 1){
			printf("%d\n", k);
			continue;
		}

		minsofar = k;

		knapsack_supersum(k, k-1);

		printf("%d\n", k-minsofar);
	}
	return 0;
}