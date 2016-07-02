#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define LT 200000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	s(t);
	char s1[LT+1], s2[LT+1];
	char * ptr, * ptr2;
	int ct1, ct2, len;
	bool fail;

	while (t--){
		scanf("%s %s", s1, s2);
		len = strlen( s1 );

		fail = 0;
		for (i=0; i<len; i++)
			if (s1[i] == '#')
				if (s2[i] == '#')
					fail = 1;
		if (fail){
			printf("No\n");
			continue;
		}

		ptr = s1; ptr2 = s2; ct1 = LT+1;
		if (ptr[0] != '#'){
			ct1 = 0;
			for (i=0; i<(len-1); i++){
				if (ptr[i+1] == '.')
					continue;
				else {
					swap(ptr, ptr2); ct1++;
				}
			}
		}

		ptr = s2; ptr2 = s1; ct2 = LT+1;
		if (ptr[0] != '#'){
			ct2 = 0;
			for (i=0; i<(len-1); i++){
				if (ptr[i+1] == '.')
					continue;
				else {
					swap(ptr, ptr2); ct2++;
				}
			}
		}

		printf("Yes\n%d\n", min(ct1, ct2));

	}

	return 0;
}