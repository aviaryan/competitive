#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int min(int a, int b){ return a>b ? b : a; }

int main(){
	int isodd=0, steps=0;
	int n, m;

	scanf("%d %d", &n, &m);
	if (n>=m)
		printf("%d", n-m);
	else {
		if (m%2 != 0)
			isodd=1, m++;
		int w1, w2;

		while (m != n){
			if (m%2 != 0)
				m++, steps++;
			else if ((m/2) >= n)
				m /= 2, steps++;
			else {
				w1 = 1 + n-(m/2); // go less then add
				//w2 = m-n;
				steps += w1;
				break;
			}
		}

		printf("%d", (isodd==1) ? steps+1 : steps);
	}

	return 0;
}