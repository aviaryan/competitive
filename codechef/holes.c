#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t, i;
	scanf("%d", &t);
	int arr[] = { 1, 2, 0, 1, 0, 0, 0, 0
				, 0, 0, 0, 0, 0, 0, 1, 1
				, 1, 1, 0, 0, 0, 0, 0, 0
				, 0, 0};

	char str[100];
	while (t--){
		scanf("%s", str);
		int holes=0;
		for (i=0; i<strlen(str); i++)
			holes += arr[ (int) str[i]-65 ];
		printf("%d\n", holes);
	}
	return 0;
}