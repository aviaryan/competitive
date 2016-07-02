#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int s,n, oindex=-1;
	scanf("%d%d", &s, &n);
	int arr[n], i;
	for (i=0; i<n; i++){
		scanf("%d", arr+i);
		if (arr[i] == s)
			oindex = i;
	}

	printf("%d", oindex);

}
