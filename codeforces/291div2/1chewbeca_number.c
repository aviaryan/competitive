#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	char str[20];
	scanf("%s", str);
	int j = strlen(str);

	int i, nk;
	for (i=0; i<j; i++){
		nk = (int) str[i] - 48;
		if (i==0)
			if (nk==9)
				continue;
		if (nk > 4)
			str[i] = (char) 9-nk + 48;
	}

	printf("%s", str);

	return 0;
}