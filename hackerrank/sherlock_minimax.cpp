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
	int t, i, n, p, q;
	int arr[100];
	s(n);
	for (i = 0; i < n; i++)
		s(arr[i]);
	sort(arr, arr+n);
	s(p); s(q);

	int min_m = p, max_diff = 0, med, t_diff, t_min_m;
	for (i=0; i<n-1; i++){
		med = (arr[i] + arr[i+1])/2;
		if (p <= med && q >= med){
			t_diff = min(med-arr[i], arr[i+1]-med);
			if (t_diff > max_diff){
				max_diff = t_diff;
				min_m = med;
			}
		} else {
			t_diff = max( min(abs(p-arr[i]), abs(p-arr[i+1])) , min(abs(q-arr[i]), abs(q-arr[i+1])) );
			t_min_m = ( t_diff == min(abs(p-arr[i]), abs(p-arr[i+1])) ) ? p : q;
			if (!(arr[i] <= t_min_m && arr[i+1] >= t_min_m))
				continue;
			if (t_diff > max_diff){
				max_diff = t_diff;
				min_m = t_min_m;
			}
		}
	}

	if (p < arr[0]){
		if (abs(arr[0]-p) >= max_diff){ // as p is least possible so equal to
			max_diff = abs(arr[0]-p);
			min_m = p;
		}
	}
	if (q > arr[n-1]){
		if (abs(arr[n-1]-q) > max_diff){
			max_diff = abs(arr[0]-q);
			min_m = q;
		}
	}

	p(min_m);

	return 0;
}