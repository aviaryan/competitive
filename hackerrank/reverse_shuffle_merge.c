#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	char str[10001], otr[5001];
	int aps[26] = {0}, z, i, k=0;

	scanf("%s", str);
	for (i=0; i<strlen(str); i++)
		aps[ (int) str[i] - 97 ]++;
	
	for (i=0; i<26; i++){
		z = aps[i] / 2;
		for (;z>0;z--){
			otr[k++] = (char) i+97;
		}
	}
	otr[k] = '\0';

	printf("%s", otr);
	return 0;
}