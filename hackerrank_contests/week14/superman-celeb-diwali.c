#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

int n,h,i;
int builds[1900][1900];
int people[1900][1900];

int solve_bottomtop(){
	int j, k;
	int premx = 0, tmp, tmp1;
	int z;
	for (j=0; j<h; j++){
		if (j-i >= 0){ // premx if superman switches building
			premx = 0, z = j-i;
			for (k=0; k<n; k++){
				if (builds[k][z] > premx)
					premx = builds[k][z];
			}
		}
		for (k=0; k<n; k++){
			tmp = people[k][j];
			if (j > 0)
				tmp1 = builds[k][j-1];
			else
				tmp1 = 0;
			if (premx > tmp1)
				tmp1 = premx;
			builds[k][j] = tmp + tmp1;
		}
	}
	// calc ans
	premx = 0;
	for (j=0; j<n; j++){
		if (builds[j][h-1] > premx)
			premx = builds[j][h-1];
	}
	return premx;
}

int solvef1(){
	int j,k,mx,ans=0;

	for (k=h-1; k>=0; k--){
		mx = 0;
		for (j=0; j<n; j++){
			if (people[j][k] > mx)
				mx = people[j][k];
		}
		ans += mx;
	}
	return ans;
}

int main(){
	scanf("%d %d %d", &n, &h, &i);
	int j, k, l, tmp;

	for (j=0; j<n; j++)
		for (l=0; l<h; l++){
			people[j][l] = 0;
			//builds[j][l] = -1;
		}
		
	for (j=0; j<n; j++){
		scanf("%d", &k);
		for (l=0; l<k; l++){
			scanf("%d", &tmp);
			people[j][tmp-1]++;
		}
	}

	if (i==1){
		printf("%d\n", solvef1());
		return 0;
	}
	int max=solve_bottomtop();
	/*for (j=0; j<n; j++){
		tmp = solve(j, h-1);
		if (tmp>max)
			max = tmp;
	}*/

	printf("%d\n", max);
	return 0;
}