#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, arr[n+2], signs[n];

	arr[0] = -1, arr[n+1] = 1000001;
	for (i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	

	int c=0, prerev, pre=arr[1], postrev, preind, postind; // c=1 reverse , 2 swap
	for (i=2; i<=n; i++){
		if (arr[i]<pre){
			c = 1;
			break;
		}
		pre = arr[i];
	}
	if (c==0){ // already sorted
		printf("yes\n");
		return 0;
	}

	// swap

	pre = arr[1], preind = -1;
	for (i=2; i<=(n+1); i++){

		if (preind==-1){
			if (arr[i] < pre)
				preind = i-1;
		}
		if (arr[i] < pre){
			postind = i;
		}
	}

	// reverse
	c = 0, pre = arr[0], prerev=-2, postrev=arr[n], postind=-1;

	for (i=1; i<=n; i++){

		if (postind > -1)
			if (arr[i]<pre){
				c = 1; // asking 2 times reverse
				break; 
			}

		if (prerev == -2){
			if (arr[i]<pre)
				prerev = arr[i-2], preind = i-1;
		} else {
			if (arr[i]>pre){
				postrev = arr[i-1], postind = i-1, arr[i-1]=arr[preind];
			}
		}

		pre = arr[i];
	}

	if (postind==-1)
		postind = n;

	//printf("%d_%d_%d_%d", postrev, prerev, arr[postind+1], arr[postind]);

	if (prerev != -2 && c == 0){
		if (postrev >= prerev && arr[postind+1]>arr[postind] ){
		// 1 5 4 3 2 6 - 2>1
		// 6>5
			if (postind-preind == 1)
				printf("yes\nswap %d %d\n", preind, postind);
			else
				printf("yes\nreverse %d %d\n", preind, postind);
			return 0;
		}
	}

	printf("no\n");
	return 0;
}
