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
	int t, i;
	char str[100];
	scanf("%s", str);
	int n = strlen(str);
	int ans = 0;

	for (i=0; i<n; i++){
		if (i%3 == 0 || i%3 == 2){
			if (str[i] != 'S')
				ans++;
		} else if (str[i] != 'O')
			ans++;
	}

	p(ans);

	return 0;
}