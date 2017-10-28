// ballons

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
	int t, i, j;
	cin >> t;
	double arr[t], k;
	for (i=0; i<t; i++){
		scanf("%lf", &arr[i]);
	}
	scanf("%lf", &k);
	sort(arr, arr+t);
	double vol = 0, cv;
	for (i=0; i<t; i++){
		cv = (4.0/3.0) * 3.14 * arr[i] * arr[i] * arr[i];
		for (j=0; j<(t-i-1); j++){
			cv = ((100.0-k)/100.0) * cv;
		}
		// printf("dd %lf\n", cv);
		vol += cv;
	}
	// printf("%.2lf\n", vol);
	// printf("%.2lf\n", ((ll)(100LL * vol)) / 100.0);
	// https://stackoverflow.com/questions/12738892/
	double var_trunc = floor(vol * 100.0) / 100.0;
	printf ("%.2lf\n", var_trunc);

	return 0;
}
