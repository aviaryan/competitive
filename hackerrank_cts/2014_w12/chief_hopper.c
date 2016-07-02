#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// 3 6 1 7 9 - 4
// 4 7 3 1 5 - 5

// 3 4 3 2 4 - 4
// 1 8 1 9 - 4
// 2 101 103 6 - 40

int main() {

	long long n;
    scanf("%lld", &n);
	long long int ce=0, iener=0, k, i, j, j2, m, z;
	long long arr[n];

	for (i=0; i<n; i++){

		scanf("%lld", &arr[i]);

		if (i==0){
			iener = arr[0]/2 + (arr[0]%2);
			ce += iener - (arr[0]-iener);
		} else {

			k = arr[i];

			if (k>ce){
				j = k-ce;
				ce -= (k-ce);
				if (ce<0){
					ce+=j;
					iener++;
					m = (i>16) ? 200001 : pow(2,i);
					ce += m;

					z = k/2 + (k%2);
					//printf("_%lld-%lld_", i, ce);

					if ((z - ce) < 0){
						ce += (ce-k);
						continue;
					}

					j = (z - ce) / m;
					j2 = (z - ce) % m;

					if (j2==0){
						iener += j;
						ce += m*j;
					} else {
						iener += j+1;
						ce += m*(j+1);
					}

					ce += (ce-k);
				}
			} else {
				ce += (ce-k);
			}

		}

	}

	printf("%lld", iener);
    return 0;
}
