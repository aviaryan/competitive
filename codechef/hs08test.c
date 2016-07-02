#include <stdio.h>

int main(){
	float n,ac;
	scanf("%f %f", &n, &ac);
	if ((n+0.5)>ac || ((int) n)%5!=0)
		printf("%.2f", ac);
	else
		printf("%.2f", ac-n-0.5);
	return 0;
}