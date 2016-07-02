#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int n, a[15], *addr, i, j, win, comp, old;
	for (;t>0;t--){
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d", a+i);

		comp = 0;
		win = 0;

		while (comp==0){

			old = a[0];
			comp = 1;

			for (j=1; j<n; j++){
				if (a[j] < old){ // TODO: check for equal
					// delete it
					for (i=j-1; i<n-1; i++){
						a[i] = a[i+1]; // make previous same as current 1 5 2 = 1 2 2
					}
					n--;
					comp = 0;
					break;
				}
				old = a[j];
			}

			printf("#%d#", a[0]);
			win = ~(win);
		}

		printf("%s\n", win==0 ? "Alice" : "Bob");
	}
}
