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

// 5 2 1 4

int main(){
	int t, i, k, n, j;
	scanf("%d %d", &n, &k);
	// as n/2 choose bool attendance
	bool attendance[n+1];
	fill_n(attendance, n+1, false);

	for (i=0; i<k; i++){
		s(j);
		attendance[j] = true;
	}

	int prev = -1, total=0;
	for (i=1; i<=n; i++){
		if (attendance[i]){
			total += (int) (i - prev - 2)/2;
			//p(total);
			prev = i;
		}
	}
	total += (n - prev)/2;

	printf("%d", k + total);

	return 0;
}