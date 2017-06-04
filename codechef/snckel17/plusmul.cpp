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
	//ios_base::sync_with_stdio(0);
	s(t);
	ull arr[100000];
	ull prevSums, prevLeft, prevCtMax, oldPrevSums, pw;

	while (t--){
		s(n);
		for (i=0; i<n; i++){
			scanf("%llu", &arr[i]);
		}
		prevSums = arr[0];
		prevCtMax = arr[0];
		prevLeft = 0;
		pw = 0;
		for (i=1; i<n; i++){
			if (i == 1){
				pw = 1;
			} else {
				pw = m(2LL * pw);
			}
			oldPrevSums = prevSums;
			prevSums = m(m(pw * arr[i]) + prevSums);
			prevSums = m(prevSums + m(prevLeft + m(prevCtMax * arr[i])));
			// printf("dbg %d %llu\n", i, prevSums);
			prevLeft = m(oldPrevSums + prevLeft);
			prevCtMax = m(m(arr[i] * pw) + m(arr[i] * prevCtMax));
			// printf("pl %llu pmc %llu\n", prevLeft, prevCtMax);
		}
		printf("%llu\n", prevSums);
	}

	return 0;
}
