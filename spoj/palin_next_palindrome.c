#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t, i;
	scanf("%d", &t);

	char str[1000001];
	int slen, ismin, sz;

	while (t--){
		scanf("%s", str);
		sz = strlen(str), slen = sz/2;
		ismin = -1;
		for (i=0; i<slen; i++){
			if (str[i] != str[sz-i-1]){
				if (str[i] > str[sz-i-1])
					ismin = 0;
				else // less than
					ismin = 1;
				str[sz-i-1] = str[i];
			}
		}

		if (ismin == -1 || ismin == 1){ // number was already palin || number is less than given
			// forced palindrome
			if (sz%2 != 0) // num is odd - include the middle term
				slen++;
			for (i=slen-1; i>=0; i--){
				if (str[i] == '9'){
					str[i] = '0', str[sz-i-1] = '0';
					continue;
				} else {
					str[i]++, str[sz-i-1] = str[i];
					break;
				}
			}
		}

		if (i==-1) // possible when input = 999 - o/p by above algo is 000
			printf("1%s1\n", &str[1]);
		else
			printf("%s\n", str);
	}
	return 0;
	// look at my code, my code is amazing
}