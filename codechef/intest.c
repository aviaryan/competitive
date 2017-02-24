#include <stdio.h>

int main(){
	int n,k, in;
	scanf("%d %d", &n, &k);

	int ct=0;
	for (;n>0;n--){
		scanf("%d", &in);
		if (in%k == 0)
			ct++;
	}
	printf("%d", ct);
	return 0;
}