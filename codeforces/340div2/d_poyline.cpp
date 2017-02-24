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

bool between(int c, int a, int b){
	return (a < c && b > c) || (a > c && b < c);
}

int main(){
	int t, i, x1, y1, x2, y2, x3, y3;
	ios_base::sync_with_stdio(0);
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int score = 0;
	if (x1 == x2 && x2 == x3){
		cout << 1 << endl;
	} else if (y1 == y2 && y2 == y3){
		cout << 1 << endl;
	} else {
		int ans;
		if (x1 == x2){
			if (between(y3, y1, y2))
				ans = 3;
			else
				ans = 2;
		} else if (x2 == x3){
			if (between(y1, y2, y3))
				ans = 3;
			else
				ans = 2;
		} else if (x3 == x1){
			if (between(y2, y1, y3))
				ans = 3;
			else
				ans = 2;
		} else if (y1 == y2){
			if (between(x3, x1, x2))
				ans = 3;
			else
				ans = 2;
		} else if (y2 == y3){
			if (between(x1, x3, x2))
				ans = 3;
			else
				ans = 2;
		} else if (y3 == y1){
			if (between(x2, x3, x1))
				ans = 3;
			else
				ans = 2;
		} else {
			ans = 3;
		}
		cout << ans << endl;
	}

	return 0;
}