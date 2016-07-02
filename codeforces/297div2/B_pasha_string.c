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

int main(){
	int n, i;
	char str[200001];
	scanf("%s", str);
	scanf("%d", &n);
	int slen = strlen(str);
	int slen2 = slen/2;

	int arr[slen2 + 1];
	for (i=0; i<slen2; i++)
		arr[i] = 0;
	int q;

	while (n--){
		scanf("%d", &q);
		arr[q-1]++;
	}

	char str2[slen+1];

	if (slen%2 != 0) str2[slen2] = str[slen2];

	for (i=0; i<slen2; i++){
		if (i>0) arr[i] += arr[i-1];
		if (arr[i] % 2 == 0)
			str2[i] = str[i], str2[slen-i-1] = str[slen-i-1];
		else
			str2[i] = str[slen-i-1], str2[slen-i-1] = str[i];
	}

	str2[slen] = '\0';
	printf("%s", str2);

	return 0;
}