#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n[5];
	int t;
	for (t=0; t<5; t++){
		scanf("%d", &n[t]);
	}  
	int n2[4], n3[3];
	// reduce to 4
	for (t=0; t<4; t++){
		n2[t] = n[t+1] - n[t];
	}
	// reduce to 3
	for (t=0; t<3; t++){
		n3[t] = n2[t+1] - n2[t];
	}
	// check
	if (n3[0]+n3[2] == 2*n3[1]) {
		printf("y");
	} else 
		printf("n");
    return 0;
}