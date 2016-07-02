#include <stdio.h>

#define MODN 1000000007

int convert_input(int K[],char string[7 * 100000])
{
int j=0,i=0,temp=0;
while(string[i]!='\0')
{
    temp=0;
    while(string[i]!=' ' && string[i]!='\0')
        temp=temp*10 + (string[i++]-'0') ;
    if(string[i]==' ')
        i++;
    K[j++]=temp;
}
return j-1;
}

int convert_input_llu(unsigned long long K[],char string[7 * 100000])
{
unsigned long long temp=0, j=0,i=0;
while(string[i]!='\0')
{
    temp=0;
    while(string[i]!=' ' && string[i]!='\0')
        temp=temp*10 + (string[i++]-'0') ;
    if(string[i]==' ')
        i++;
    K[j++]=temp;
}
return j-1;
}


int main() {
	int n,m,i,j,c,k;
	scanf("%d %d", &n, &m);
	unsigned long long a[n];
	char str[7 * 100000], tc;
	int b[m];

	scanf("%c", &tc);
	gets(str);
	j = convert_input_llu(a, str);

	scanf("%c", &tc); // catch enter
	gets(str);
	j = convert_input(b, str);

	for (i=0; i<m; i++){
		scanf("%d", &c);
		for (j=b[i]; j<=n; j+=b[i])
			a[j-1] = c*a[j-1] % MODN;
	}

	for (i=0; i<n; i++)
		printf("%llu ", a[i]);
}