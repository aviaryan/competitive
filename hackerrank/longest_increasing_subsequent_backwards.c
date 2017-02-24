#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t;
	scanf("%d", &t);

	int i, j, arr[t], lis=1, local_lis;
	int lis_arr[t];
	// memset(arr, value, size_to_go)
	for (i=0; i<t; i++)
		scanf("%d", arr+i);

	for (i=t-1; i>=0; i--){
		local_lis=0;
		for (j=i+1; j<t; j++){
			if (arr[j] > arr[i])
				if (lis_arr[j] > local_lis)
					local_lis = lis_arr[j];
		}
		lis_arr[i] = 1+local_lis;
		if (lis_arr[i] > lis)
			lis = lis_arr[i];
	}

	printf("%d", lis);
	return 0;
}