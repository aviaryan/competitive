#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int reverseNum(int a){
	int s=0,r;
	while (a){
		r = a%10;
		s = s*10 + r;
		a/=10;
	}
	return s;
}

int main(){
	int t, a, b;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &a, &b);
		a = reverseNum(a);
		b = reverseNum(b);
		printf("%d\n", reverseNum(a+b));
	}
	return 0;
}