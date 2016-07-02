#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	char str[100000], *c, oc;
	int i,d;

	for (i=0; i<n; i++){
		scanf("%s", str);
		c = &str[0];
		d = 0;
		oc = ' ';

		while (c[0] != '\0'){
			if (c[0] == oc){
				d++;
			}
			oc = c[0];
			c++;
		}

		printf("%d\n", d);
		str[0] = '\0';
	} 
    return 0;
}
