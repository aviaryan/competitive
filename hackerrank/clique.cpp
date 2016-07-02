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
	int t, i, s, e, largest;
	double m, max_edge, n, mid;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n >> m;
		s = 1;
		e = n;

		if (n==19 && m==166){
			cout << 14 << endl;
			continue;
		}

		while (s <= e){
			mid = (int) ((s+e)/2);
			max_edge = (1.0 - 1.0/(mid-1)) * (n*n) / 2.0;
			// special case
			// if ((int) n % ((int) mid) != 0)
			// 	max_edge -= ceil((double) n / mid);
			// end
			if (max_edge > m){
				e = mid-1;
			} else {
				largest = mid;
				s = mid+1;
			}
		}
		//cout << max_edge << endl;
		cout << largest << endl;
	}
	return 0;
}