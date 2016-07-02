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

	int i, arr[t], lis=1, clis, j, k, last;
	bool arrin[t];
	for (i=0; i<t; i++)
		scanf("%d", arr+i), arrin[i] = 0;
	
	for (i=0; i<(t-1); i++){

		clis = 1;
		last = arr[i];
		j = i+1;
		if (arrin[i] == 0){
			for(j=i+1; j<t; j++){
				if (arr[j] > last){
					clis++;
					k = j+1;
					while (k<t){
						if (arr[k]>arr[j])
							break;
						else if (arr[k]>last){
							arrin[j] = 1;
							j = k;
						}
						else
							break;
						k++;
					}
					arrin[j] = 1;
					last = arr[j];
					printf("%d-", last);
				}
			}
			arrin[i] = 1;
			if (clis > lis)
				lis = clis;
		}

	}

	printf("%d", lis);

	return 0;
}