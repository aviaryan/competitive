#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int n,m,a;
	scanf("%d %d %d", &n, &m, &a);
	unsigned long long np,mp;
	np = n%a == 0 ? n/a : n/a + 1;
	mp = m%a == 0 ? m/a : m/a + 1;
	printf("%I64d", np*mp);
	return 0;
}