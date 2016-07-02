#include <stdio.h>
#include <malloc.h>

int **matrix, **cofs, ***arr, dim;

void hide_xy(int, int, int);

main(){
	int t1, t2, t3;
	printf("Welcome to Matrix Inverse Program. Please write down dimension of the needed matrix\n");
	scanf("%d", &dim);

	if (dim==1){
		puts("Are you a toddler ? Nonsense");
		return;
	}

	// Alloc
	matrix = (int**)calloc(dim, sizeof(int*));
	cofs = (int**)calloc(dim, sizeof(int*));
	for (t1=0;t1<dim;t1++){
		matrix[t1] = (int*)calloc(dim, sizeof(int));
		cofs[t1] = (int*)calloc(dim, sizeof(int));
	}

	// Alloc arr
	arr = (int***)calloc(dim, sizeof(int**));
	for (t1=0;t1<dim;t1++){
		
		arr[t1] = (int**)calloc(t1+1, sizeof(int*));
		for (t2=0;t2<=t1;t2++){
			arr[t1][t2] = (int*)calloc(t1+1, sizeof(int));

			for (t3=0; t3<t1+1; t3++){
				arr[t1][t2][t3] = 0;
			}
		}
	}

	// Input
	printf("\n=== Now input the matrix ===\n\n");
	for (t1=0; t1<dim; t1++){
		for(t2=0; t2<dim; t2++){
			scanf("%d", &matrix[t1][t2]);
			arr[dim-1][t1][t2] = matrix[t1][t2];
		}
	}

	int det = 0;
	// Loop for Cofactors
	for (t1=0; t1<dim; t1++){
		for (t2=0; t2<dim; t2++){
			hide_xy(dim, t1, t2);
			cofs[t1][t2] = ( ( (t1+t2)%2 == 0 ) ? 1 : -1 ) * detm(dim-1);
			if (t1==0)
				det += matrix[0][t2] * cofs[0][t2];
		}
	}

	if (det==0){
		printf("\nAs Determinant is 0, there exists no inverse");
		return;
	}

	printf("\n");
	int hc ;
	// Display
	for (t2=0; t2<dim; t2++){
		for (t1=0; t1<dim; t1++){
			hc = hcf( det, cofs[t1][t2] );
			printf("   [ %d/%d ]   ", cofs[t1][t2]/hc, det/hc);
		}
		printf("\n");
	}
}

int hcf(int a, int b){
	return (b==0) ? a : hcf( b , a%b );
}

int detm(int sz){
	int t1, sum=0;
	if (sz==1)
		return arr[0][0][0];
	else if (sz==2)
		return ( arr[1][0][0] * arr[1][1][1] ) - ( arr[1][1][0] * arr[1][0][1] );
	else {
		for (t1=0; t1<sz; t1++){
			hide_xy(sz, 0, t1);
			sum += arr[sz][0][t1] * detm(sz-1);
		}
		return sum;
	}
}

void hide_xy(int sz, int row, int col){
	int t1,t2;
	int tt1=-1, tt2=-1;

	for (t1=0; t1<sz; t1++){
		if (t1==row)
			continue;
		else
			tt1++;

		tt2 = -1;
		for (t2=0; t2<sz; t2++){
			if (t2==col)
				continue;
			else
				tt2++;
			arr[sz-2][tt1][tt2] = arr[sz-1][t1][t2];
		}
	}
}