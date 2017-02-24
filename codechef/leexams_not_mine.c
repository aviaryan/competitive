#include<stdio.h>
int a[52],b[52],c[52],d[20],e[20],n;
double fifa(int p)
{
    double i,j;
    if(p==n+1)
    {
        return 1.0;
    }
    else
    {
        if(d[b[p]]==1)
        {
            i=0.0;
        }
        else
        {
            d[b[p]]=1;
            i=fifa(p+1)*(a[p]/100.0);
            d[b[p]]=0;
        }
        if(d[c[p]]==1)
        {
            j=0.0;
        }
        else
        {
            d[c[p]]=1;
            j=fifa(p+1)*((100.0-a[p])/100);
            d[c[p]]=0;
        }
        return i+j;
    }
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        }
        for(i=0;i<20;i++)
        {
            d[i]=0;
        }
        printf("%lf\n",fifa(1));
    }
    return 0;
}