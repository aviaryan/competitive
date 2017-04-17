#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, i = 2;
	scanf("%d", &n);
	char bit[100000]; 

	scanf("%s", bit);
	char p[100000] = "0";
	char q[100000] = "1";
	char r[100000];

	while (n>i){
		r[0] = '\0';
		strcpy(r, q);
		strcat(r, p);
		p[0] = '\0';
		strcpy(p, q);
		q[0] = '\0';
		strcpy(q, r);
		i++;
	}
	if (n<=0){
		q[0] = '\0';
	}
	if (n==1){
		q[0] = '\0';
		strcpy(q,p);
	}

	char *sPtr;
	sPtr = &q[0];
	int ct=0;

	while ( (sPtr = strstr(sPtr, bit)) != NULL ){
		ct++;
		if (sPtr[0] != '\0' )
			sPtr++;
	}

	printf("%d", ct);
    return 0;
}