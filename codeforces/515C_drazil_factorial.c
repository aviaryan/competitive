#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int t, i, j;
	scanf("%d", &t);
	int a[t];
	int anarr[8] = {0};

	for (i=0; i<t; i++){
		scanf("%1d", &a[i]);
		if (a[i]==4)
			anarr[0]+=2, anarr[1]++; // 3! 2! 2!
		else if (a[i]==6)
			anarr[3]++, anarr[1]++; // 5! 3!
		else if (a[i]==8)
			anarr[5]++, anarr[0]+=3; // 2! 2! 2!
		else if (a[i]==9)
			anarr[5]++, anarr[0]+=1, anarr[1]+=2; // 7! 2! 3! 3!
		else if (a[i]>1)
			anarr[a[i]-2]++;
	}

	for (i=7; i>=0; i--){
		for (j=0; j<anarr[i]; j++)
			printf("%d", i+2);
	}


	return 0;
}