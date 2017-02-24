#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	int n,m;
	scanf("%d %d", &n, &m);
	char arr[n][m+1];
	int i,j,i2,j2,i3,j3;
	long ct;
	// input
	for (i=0; i<n; i++)
		scanf("%s", arr[i]);

	// go forth
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
		// got dimensions - now scan
			ct = 0;

			for (i2=0; i2<n-i; i2++){
				for (j2=0; j2<m-j; j2++){
				// got init point to scan (leftmost) - now large

					for (i3=i2; i3<=i2+i; i3++)
						for (j3=j2; j3<=j2+j; j3++)
							if ( arr[i3][j3] == '0' ){
								ct--; //optimize
								break;
							}
					ct++;
				// end scan
				}
			}

			printf("%lu ", ct);
		// end of one dimension
		}
		printf("\n");
	}


	return 0;
}
