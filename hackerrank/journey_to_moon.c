#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,l,a,b,t,i;
    scanf("%d%d",&n,&l);
    if(n==1)
    {
        printf("0\n");
        return(0);
    }
    
    long long int ans=0;
   
    // code to compute answer
    int *anots[n]; // pointer holds an astronaout group number
    int groups[n+1], cGid = 1, nGid;

    for (i=0; i<n; i++){ // init variables
        groups[i] = 0;
        anots[i] = NULL;
    }

    for (i=0; i<l; i++){
        scanf("%d %d", &a, &b);

        if ( anots[a] != NULL && anots[b] != NULL ){
            nGid = *anots[a];
            groups[ *anots[b] ] = nGid;
        } else if ( anots[a] != NULL ){
            nGid = *anots[a];
            anots[b] = &groups[ nGid ];
        } else if ( anots[b] != NULL ){
            nGid = *anots[b];
            anots[a] = &groups[ nGid ];
        } else {
            groups[ cGid ] = cGid;
            anots[a] = &groups[ cGid ];
            anots[b] = &groups[ cGid ];
            cGid++;
        }

    }

    // calculate no of mems in group
    int groupct[ cGid ]; // cGid is always one extra - 0 groupct is for single members
    for (i=0; i<cGid; i++)
        groupct[i] = 0;

    for (i=0; i<n; i++){
        if ( anots[i] == NULL )
            groupct[0]++;
        else
            groupct[ *anots[i] ]++;
    }

    // calculate no of ways
    for (i=0; i<cGid; i++){
        if (i==0){
            for (t=0; t<groupct[0]; t++)
                ans += (n-1);
        } else {
            ans += groupct[i] * (n - groupct[i]);
        }
    }

    printf("%lld\n", (ans/2) );
    return(0);
}