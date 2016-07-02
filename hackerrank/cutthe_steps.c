#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, i, ct;
	scanf("%d", &n);
	int arr[n];
	int min = 1001;

	for (i=0; i<n; i++){
		scanf("%d", &arr[i]);
		if (arr[i]<min)
			min = arr[i];
	}

	while (2>1){
		
		ct = 0;
		for (i=0; i<n; i++){
			if (arr[i] >= min){
				arr[i] -= min;
				ct++;
			}
		}
		if (ct ==0 )
			break;
		printf("%d\n", ct);

		// calc min
		min = 1001;
		for (i=0; i<n; i++){
			if (arr[i] == 0)
				continue;
			if (arr[i]<min)
				min = arr[i];
		}

	}

	return 0;
}