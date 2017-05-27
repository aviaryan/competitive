#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n;
	s(t);
	char s1[501];
	char s2[501];
	int prev; // 0 first 1 down 2 both
	bool snakeOver, snakeStarted;

	while (t--){
		s(n);
		scanf("%s", s1);
		scanf("%s", s2);
		assert(strlen(s1) == strlen(s2));
		prev = 2;
		snakeOver = false; snakeStarted = false;
		for (i=0; i<n; i++){
			if (s1[i] == '#' && s2[i] == '#'){
				if (snakeOver) break;
				snakeStarted = true;
				if (prev == 1)
					prev = 0;
				else if (prev == 0)
					prev = 1;
			} else if (s1[i] == '#' && s2[i] == '.'){
				if (snakeOver) break;
				snakeStarted = true;
				if (prev == 1)
					break;
				if (prev == 2)
					prev = 0;
			} else if (s1[i] == '.' && s2[i] == '#'){
				if (snakeOver) break;
				snakeStarted = true;
				if (prev == 0)
					break;
				if (prev == 2)
					prev = 1;
			} else {
				if (snakeStarted)
					snakeOver = true;
			}
		}
		printf("%s\n", (i==n) ? "yes" : "no");
	}

	return 0;
}