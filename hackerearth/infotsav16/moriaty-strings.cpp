// by saurabhjn76
#include "bits/stdc++.h"
using namespace std;

# define MOD 1000000007



int main()
{
	int i,j,k,l,n,m,t;
	scanf("%d",&t);
	char a[1000];
	int b[26];
	int c[26];
	
	while(t--){
		for( j=0;j<26;j++)
		c[j]=j;
		for( j=0;j<26;j++)
		c[j]=j;
		for(i=0;i<26;i++)
			b[i]=0;

		scanf("%s",a);
		l=strlen(a);
		for(i=0;i<l;i++){
			b[a[i]-'a']++;
		}
		/*for(i=0;i<26;i++)
			printf("%d ",b[i] );
		printf("\n");*/
		for(i=0;i<26;i++){
			for(j=0;j<26-i-1;j++){
				if(b[j]>b[j+1]){
					m=b[j];
					b[j]=b[j+1];
					b[j+1]=m;
					m=c[j];
					c[j]=c[j+1];
					c[j+1]=m;
				}
			}
		}
		// for(i=0;i<26;i++)
		// 	printf("%d ",c[i] );
		for(i=0;i<26;i++){
			if(b[i]!=0){
				for(int j=0;j<b[i];j++)
				printf("%c",c[i]+97);
			}
		}
		printf("\n");
	}
	
	return 0;
}
	