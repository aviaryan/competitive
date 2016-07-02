#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long arr[100000];
long arrct[100000];

int main() {
	int t, n;
	scanf("%d", &t);

	int i, j;
	int i2, i3, i4;
	long res=0, tres;
	for (i=0; i<t; i++){
		scanf("%d", &n);
		res = 0;
		for (j=0; j<n; j++) // get in
			scanf("%lu", arr + j);
		// calc

		/*for (i2=0; i2<n; i2++){
				tres = 0;
			for (i3=i2; i3<n; i3++){
				tres = tres ^ arr[i3];
				res = res ^ tres;
			}
		}*/

		long nct;
		for (i2=0; i2<n; i2++){
			nct = (i2+1)*(n-i2);
			/*for (i3=0; i3<i2; i3++){
				nct += (n-(i2-i3))-(i3); // first part (n-(i2-i3)) for total occurences, second part -i3 to remove invalid in contiguous series.
			}*/
			if (nct%2!=0)
				res ^= arr[i2];
		}


		printf("%lu\n", res);
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
