#include "stdio.h"

main(){
	printf("This is Matrix program for addition.\nYou will be asked to enter 2 matrices.\nEnter the rows and columns of matrices.\n");
	int r,c;
	scanf("%d%d", &r, &c);
	int a[r][c];
	int b[r][c];
	// first matrix starts
	int t1, t2;
	// ack
	printf("\nWrite 1st matrix - %d columns - separated by spaces\n\n", c);
	for(t1=1; t1<=r; t1++){
		for(t2=1; t2<=c; t2++){
			scanf("%d", &a[t1-1][t2-1]);
		}
	}
	printf("\n\nDone with the first matrix.\n\n");
	// 2nd matrix
	printf("Write 2nd matrix - %d columns - separated by spaces\n\n", c);
	for(t1=1; t1<=r; t1++){
		for(t2=1; t2<=c; t2++){
			scanf("%d", &b[t1-1][t2-1]);
		}
	}

	printf("\n\n");
	// Add them
	int res[r][c];
	for(t1=1; t1<=r; t1++){
		for(t2=1; t2<=c; t2++){
			res[t1-1][t2-1] = a[t1-1][t2-1] + b[t1-1][t2-1];
			printf("%d ", res[t1-1][t2-1]);
		}
		printf("\n");
	}
	
}
