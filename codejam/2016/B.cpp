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

// ifstream fin("input.txt");
// ifstream fin("B-small-attempt0.in");
// ofstream fout("output.txt");

char str[1001];

int main(){
	int t, i, j, l;
	scanf("%d", &t);
	bool last_minus = 0;
	int total = 0;

	for (j=1; j<=t; j++){
		scanf("%s", str);
		l = strlen(str);
		last_minus = false;
		total = 0;

		if (str[0] == '-'){
			total += 1;
			last_minus = true;
		}

		for (i=1; i<l; i++){
			if (str[i] == '-'){
				if (last_minus == false){ // no need in true
					total += 2;
					last_minus = true;
				}
			} else {
				last_minus = false;
			}
		}

		printf("Case #%d: %d\n", j, total);
	}

	return 0;
}