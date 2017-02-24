#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char s1[10001], s2[10001];
	int s1c[26] = {0}, s2c[26] = {0};
	int ans=0, ls1, ls2,i,j;

	scanf("%s%s", s1, s2);
	ls1 = strlen(s1);
	ls2 = strlen(s2);

	for (i=0;i<ls1;i++)
		s1c[ (int) s1[i] - 97 ]++;
	for (i=0;i<ls2;i++)
		s2c[ (int) s2[i] - 97 ]++;

	for (i=0;i<26;i++)
		ans += abs( s1c[i] - s2c[i] );
	
	printf("%d", ans);
}
