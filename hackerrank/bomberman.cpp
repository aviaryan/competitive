#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

char grid[200][200];
char gridc[200][200];


void inverse(char ingrid[][200], char outgrid[][200], int r, int c){
	int i, j;
	// all 0s init position
	for (i=0; i<r; i++) 
		for (j=0; j<c; j++) 
			outgrid[i][j] = 'O';
	// set 1s or dots
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			if (ingrid[i][j] == 'O'){
				outgrid[i][j] = '.';
				if (i - 1 >= 0) outgrid[i-1][j] = '.';
				if (i + 1 < r) outgrid[i+1][j] = '.';
				if (j - 1 >= 0) outgrid[i][j-1] = '.';
				if (j + 1 < c) outgrid[i][j+1] = '.';
			}
		}
	}
}

int main(){
	int t, i, r, c, n, j;
	scanf("%d %d %d", &r, &c, &n);
	char ch;

	scanf("%c", &ch);
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			scanf("%c", &grid[i][j]);
		}
		scanf("%c", &ch);
	}

	if (n < 2){
		for (i=0; i<r; i++){
			for (j=0; j<c; j++)
				printf("%c", grid[i][j]);
			printf("\n");
		}
	} else if (n % 2 == 0){
		for (i=0; i<r; i++){
			for (j=0; j<c; j++)
				printf("O");
			printf("\n");
		}
	} else if ((n-3) % 4 == 2) {
		// double inverse
		inverse(grid, gridc, r, c);
		inverse(gridc, grid, r, c);
		for (i=0; i<r; i++){
			for (j=0; j<c; j++)
				printf("%c", grid[i][j]);
			printf("\n");
		}
	} else {
		// inverse
		inverse(grid, gridc, r, c);
		// print
		for (i=0; i<r; i++){
			for (j=0; j<c; j++)
				printf("%c", gridc[i][j]);
			printf("\n");
		}
	}
	return 0;
}