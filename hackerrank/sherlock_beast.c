#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t,s;
	scanf("%d", &t);

	int i,j,n, five, three;
	for (i=0; i<t; i++){
		scanf("%d", &n);
		five = n;
		three = 0;
		s = 0;
		for (j=0; j<=n; j++){
			if ((five % 3 == 0) && (three % 5 == 0)){
				s = 1;
				break;
			}else {
				five-=1 , three+=1;
			}
		}

		if (s==1){
			for (j=0; j<five; j++)
				printf("5");
			for (j=0; j<three; j++)
				printf("3");
		} else {
			printf("-1");
		}
		printf("\n");

	}
    return 0;
}
