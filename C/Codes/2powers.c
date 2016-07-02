#include <stdio.h>

main(){
	int p;
	scanf("%d", &p);

	int s[300] = {0};
	s[299] = 1;
	int i, slen=1, j, tem, carry;

	for (i=0; i<p; i++){

		carry = 0;
		for (j=0; j<slen; j++){
			tem = (2*s[299-j]) + carry;
			carry = tem/10;
			s[299-j] = tem%10;
		}
		if (carry==1)
			s[299-j] = 1, slen++;

	}

	printf("\n");
	for (i=(300-slen); i<300; i++){
		printf("%d", s[i]);
	}
}