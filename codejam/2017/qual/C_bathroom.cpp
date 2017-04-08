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
	int t, i, tf, n, k, prev, cur;
	ios_base::sync_with_stdio(0);
	cin >> t;
	set <int> s;
	set <int>::iterator sit;
	int minx, maxx, cmin, cmax, pos, prevMinx, prevMaxx;

	for (tf=1; tf<=t; tf++){
		cin >> n >> k;
		s.clear();
		s.insert(0); s.insert(n+1);
		for (i=0; i<k; i++){
			sit = s.begin();
			prev = *sit;
			sit++;
			minx = -1; maxx = -1; pos = -1;

			for (; sit != s.end(); sit++){
				cur = *sit;
				cmin = (cur - prev - 2) / 2;
				if (cmin < 0) cmin = 0; // touched case
				cmax = (cur - prev - 1) / 2;
				if ( (cmin > minx) || (cmin == minx && cmax > maxx) ){
					minx = cmin; maxx = cmax; pos = prev + ((cur - prev) / 2);
					if (minx == prevMinx && maxx == prevMaxx) break; // already best solution
				}
				prev = cur;
			}

			s.insert(pos);
			prevMinx = minx; prevMaxx = maxx;
		}
		cout << "Case #" << tf << ": " << maxx  << " " << minx << endl;
	}

	return 0;
}