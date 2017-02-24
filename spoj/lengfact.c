#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

// http://en.wikipedia.org/wiki/Stirling%27s_approximation

int main()
{
    int t;
    scanf("%d", &t);
    ull n;
    double pi2 = asin(1)*2*2;

    while (t--)
    {
        scanf("%llu", &n);
        if (n<2)
        	printf("1\n");
        else
        	printf("%llu\n", (ull) ceil( (log(pi2*n)/2 + n*(log(n)-1))/log(10) ) );
    }
    return 0;
}