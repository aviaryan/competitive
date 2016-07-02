#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define SZ 200

int main(){
	int t;
	scanf("%d", &t);
	int p;
	int s[SZ] = {0};
	int i, slen=1, j, tem, carry, k;


	for (;t>0;t--){
		scanf("%d", &p);

		// free s
		for (i=0; i<SZ; i++)
			s[i] = 0;
		s[SZ-1] = 1, slen = 1;

		for (i=1; i<=p; i++){
			carry = 0;
			for (j=0; j<slen; j++){
				tem = (i*s[SZ-1-j]) + carry;
				carry = tem/10;
				s[SZ-1-j] = tem%10;
			}
			if (carry>0){
				tem = carry;
				k = 0;
				while (tem>0){
					s[SZ-1-j-k] = tem%10, slen++, k++;
					tem = tem/10;
				}
			}
		}

		for (i=(SZ-slen); i<SZ; i++)
			printf("%d", s[i]);
		printf("\n");
	}

	return 0;
}