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
	int t, i, a, n;
	//ios_base::sync_with_stdio(0);
	s(t);
	bool fail, excel;
	double sum;

	while (t--){
		s(n);
		fail = false;
		excel = false;
		for (i=0; i<n; i++){
			s(a);
			if (a < 3)
				fail = true;
			if (a == 5)
				excel = true;
			sum += a;
		}
		sum /= (double) n;
		if ( (excel==true) && (fail==false) && (sum >= 4.0) )
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}