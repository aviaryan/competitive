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


double status[17], bk[17];

double status_sum(){
	double k = 0;
	for (int i = 1; i<17; i++)
		k += status[i];
	return k;
}

int main(){
	int t, i;
	double p, a, b, psum;
	s(t);

	while (t--){
		s(n);
		fill_n(status, 17, 0);

		for (i=0; i<n; i++) // using a DP sort of approach (I believe, for every brute force exists a DP)
		{
			scanf("%lf %lf %lf", &p, &a, &b);
			p /= 100;
			if (i==0){
				bk[a] = p;
				bk[b] += 1-p;
				psum = 1.0;
			} else {
				bk[a] = p * (psum - status[a]);
				bk[b] = (1-p) * (psum - status[b]);
			}
			// this can be optimized
			fill_n(status, 17, 0);
			status[a] = 
		}
	}

	return 0;
}