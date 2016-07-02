#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// A - 65 a - 97

int main() {
	char str[1001];
	// scanf("%s", str);
	gets(str);
	int s=1,i;

	for (i=0;i<26;i++){
		if ( ( strchr(str, 65+i) == NULL ) && ( strchr(str, 97+i) == NULL ) ){
			s = 0;
			break;
		}
	}

	printf("%s", (s==0) ? "not pangram" : "pangram");
    return 0;
}
