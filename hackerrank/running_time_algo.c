#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	int n;
	scanf("%d", &n);

	int i,j, arr[n];
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int ct=0, t;

    for (i=0; i<n; i++){
		for (j=0; j<i; j++){
			if ( arr[i-j] < arr[i-1-j] ){
				t = arr[i-j];
				arr[i-j] = arr[i-1-j];
				arr[i-1-j] = t;
				ct++;
			} else {
				break;
			}
		}
	}

	printf("%d", ct);

    return 0;
}
