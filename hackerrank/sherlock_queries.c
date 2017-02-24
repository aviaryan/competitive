#include <stdio.h>

#define MODN 1000000007

int main() {
	int n,m,i,j,k,cin;
	scanf("%d %d", &n, &m);
	unsigned long long a[n];

	for (i=0; i<n; i++)
		scanf("%llu", &a[i]);

	int b[m];
	for (i=0; i<m; i++)
		scanf("%d", &b[i]);

	long long c[n+1];
	for (i=1; i<=n; i++)
		c[i] = 1;

	for (i=0; i<m; i++){
		scanf("%d", &cin);
		c[b[i]] = (c[b[i]] * cin) % MODN;
	}

	for (i=1; i<=n; i++){
		if (c[i] == 1)
			continue;
		for (j=i; j<=n; j+=i)
			a[j-1] = (c[i]*a[j-1]) % MODN;
	}

	for (i=0; i<n; i++)
		printf("%llu ", a[i]);

	return 0;
}