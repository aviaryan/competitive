/*
NOT optimized for larger testcase
Use a better DS with this algo and it will work
The algo is to insert that element which can be inserted and which has the largest
count among the candidates
 */

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
	int t, i, tf, r, o, y, g, b, v, n;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int co, sp, tot;
	char str[10001];

	for (tf=1; tf<=t; tf++){
		cin >> n >> r >> o >> y >> g >> b >> v;
		co = (n/2);
		if (r > co || y > co || b > co){
			cout << "Case #" << tf << ": IMPOSSIBLE" << endl;
			continue;
		}
		sp = 0; tot=0;
		char last = ' ';
		bool pass=true;

		// set last
		if (r >= y && r >= b && last != 'R'){
			str[sp++] = 'R'; tot++; r--; pass=false; last = 'R';
		}
		if (pass==true && (y >= r) && y >= b && last != 'Y'){
			str[sp++] = 'Y'; tot++; y--; pass=false; last = 'Y';
		}
		if (pass==true && (b >= y) && b >= r && last != 'B'){
			str[sp++] = 'B'; b--; tot++; last = 'B';
		}

		// int cc=0;

		while (tot < n){
			pass = true;
			if (last != 'R' && r > 0){
				if (last == 'Y' && r >= b){
					str[sp++] = 'R'; tot++; r--; pass=false; last = 'R';
				} else if (last == 'B' && r >= y){
					str[sp++] = 'R'; tot++; r--; pass=false; last = 'R';
				}
			}
			if (pass==true && (last != 'Y') && y > 0){
				if (last == 'R' && y >= b){
					str[sp++] = 'Y'; tot++; y--; pass=false; last = 'Y';
				} else if (last == 'B' && y >= r){
					str[sp++] = 'Y'; tot++; y--; pass=false; last = 'Y';
				}
			}
			if (pass==true && (last != 'B') && b > 0){
				if (last == 'R' && b >= y){
					str[sp++] = 'B'; b--; tot++; last = 'B';
				} else if (last == 'Y' && b >= r){
					str[sp++] = 'B'; b--; tot++; last = 'B';
				}
			}
			//cout << last << " ";
			// cc++;
			// if (cc > 2*n) break;
		}
		// if (b != 0 || r != 0 || y != 0){
		// 	cout << "Case #" << tf << ": IMPOSSIBLE" << endl;
		// 	continue;
		// }
		assert(b==0); assert(y==0); assert(r==0);
		// round case
		if (str[0] == str[n-1]){
			swap(str[n-2], str[n-1]);
		}
		str[n] = '\0';
		cout << "Case #" << tf << ": " << str << endl;
	}

	return 0;
}