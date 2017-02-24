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
	int t, i, n, c, j, k, ans, chef;
	int vals[100], anss[100];
	int ar[6];
	s(t);

	while (t--){
		s(n);
		for (i=0; i<n; i++){
			s(c);
			ans = 0;
			fill_n(ar, 6, 0);
			for (j=0; j<c; j++){
				s(k);
				ar[k-1]++;
			}
			sort(ar, ar+6);
			// 6
			ans += ar[0] * 4;
			ans += (ar[1] - ar[0]) * 2;
			ans += (ar[2] - ar[1]) * 1;
			ans += c;
			vals[i] = ans;
			anss[i] = ans;
		}
		// find ans
		sort(anss, anss+n);
		if (n==1){
			printf("chef\n");
		} else if (anss[n-1] == anss[n-2]){
			printf("tie\n");
		} else {
			for (i=0; i<n; i++)
				if (vals[i] == anss[n-1])
					break;
			if (i == 0)
				printf("chef\n");
			else
				printf("%d\n", i+1);
		}
	}

	return 0;
}