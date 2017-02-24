#include <stdio.h>

int main(){
	int n;
	while (2>1){
		scanf("%d", &n);
		if (n != 42)
			printf("%d\n", n);
		else
			break;
	}
	return 0;
}