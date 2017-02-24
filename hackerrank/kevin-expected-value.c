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
#define dbl double

int main(){
	int t;
	scanf("%d", &t);
	ull n, i;
	double ans=0;

	while (t--){
		scanf("%llu", &n);
		ans = 0.0;
		if (n<50000){
			for (i=1; i<n; i++)
				ans += (1+sqrt(1+4*i)) / 2; // y^2 = y + x ; y = 1+root(1+4x) /2
			ans /= n;
		}
		else {
			//ans = sqrt(n / 2) + 1/2; // y = 1/2 + root(x) - http://mathforum.org/library/drmath/view/65309.html
			n--;
			ans = ( (((dbl)2/3)*pow(n,1.5)) + (0.5*pow(n,0.5)) - ((dbl)1/6) ) + ( (((dbl)2/3)*pow(n,1.5)) + (0.5*pow(n,0.5)) + ((dbl)1/3) - (0.5*pow(2,0.5)) );
			ans = ans/(2*n);
			ans += 0.5;
		}
		printf("%.20lf\n", ans);
	}
	return 0;
}