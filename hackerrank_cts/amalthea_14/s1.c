#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n = 4;
	int i=0;
	char s1[100] = "1";
	char s2[100];
	char c;
	int t, ct=0, sfill, sen;

	int reset = 1;
	for (i=1; i<n; i++){

	sfill = 0, sen = 0;
	while (s1[sen] != '\0'){
		c = s1[sen];
		ct = 1;
		while ( s1[++sen] == c )
			ct++;
		if (s1[sen] != '\0')
			--sen; // back
		s2[++sfill] = (char) (48+ct);
		s2[++sfill] = c;
	}

	s1[0] = '\0';
	strcpy(s1, s2);
	printf("%s", s2);
	s2[0] = '\0';

	}

}