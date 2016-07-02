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
	char str[10000+1];
	for (i=0; i<10000; i++)
		str[i] = 97+(i%3);
	str[10000] = '\0';
	while (t--){
		s(n);
		printf("%s\n", &str[10000-n]);
	}

	return 0;
}