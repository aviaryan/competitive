#include <stdio.h>
#define SZ 300

main(){
	int p;
	scanf("%d", &p);

	int s[SZ] = {0};
	s[SZ-1] = 1;
	int i, slen=1, j, tem, carry, k;

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

	for (i=(SZ-slen); i<SZ; i++){
		printf("%d", s[i]);
	}
}