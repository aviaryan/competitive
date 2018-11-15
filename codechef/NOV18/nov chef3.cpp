#include<stdio.h>
#include<math.h>
int main()
{
	// jacobsthal number
    int a[25] = {1,1,3,5,11,
                 21,43,85,171,341,
                 683,1365,2731,5461,10923,
                21845,43691,87381,174763,349525,
                699051,1398101,2796203,5592405,11184811};

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int y;
        y = pow(2,n);
        printf("%d %d ",a[n-1],y);
    }
}
