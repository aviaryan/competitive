#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[1000] = {0};

void resetarr(int lt){
	int i;
	for (i=0; i<lt; i++)
		arr[i] = 0;
}

int main() {
	int k,i,i2,i3,i4, res[1000] = {0};
	int n,a,b,th;
	scanf("%d", &k);
	
	// get inputs
	for (i=0; i<k; i++){

		scanf("%d%d%d", &n, &a, &b);
		if (a>b){
			th = a;
			a = b;
			b = th;
		}

		// if equal leave
		if (a==b){
			res[0] = 0;
			for (i2=0; i2<n-1; i2++)
				res[0]+=a;
			printf("%d\n", res[0]);
			continue;
		}

		for (i2=0; i2<n-1; i2++) // make all small
			arr[i2] = a;

		for (i3=0; i3<n; i3++){ // loop all cases
			res[i3] = 0;
			for (i4=0; i4<n-1; i4++){ // count
				res[i3]+=arr[i4];
				// printf("-%d-", arr[i4]);
			}
			printf("%d ", res[i3]); // print
			// change case
			arr[i3] = b;
		}

		resetarr(i2+1);
		printf("\n");
	} 

    return 0;
}
