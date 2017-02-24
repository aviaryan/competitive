#include "bits/stdc++.h"
#define s(a) scanf("%d", &a)
using namespace std;

int main(){
	int t, i, k, a, b;
	int ans;
	s(t);

	char * ar[10];
	char s1[] = "2486"; ar[2] = s1;
	char s3[] = "3971"; ar[3] = s3;
	char s4[] = "4646"; ar[4] = s4;
	char s7[] = "7931"; ar[7] = s7;
	char s8[] = "8426"; ar[8] = s8;
	char s9[] = "9191"; ar[9] = s9;

	while (t--){
		scanf("%d %d", &a, &b);
		if (a == 0)
			ans = 0;
		else if (b == 0)
			ans = 1;
		else {
			a %= 10;
			if (a == 0)
				ans = 0;
			else if (a == 1 || a == 5 || a == 6)
				ans = a;
			else {
				b = (b-1)%4 + 1;
				ans = ar[a][b-1]-48;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}