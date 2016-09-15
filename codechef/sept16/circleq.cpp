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

// clean circles, remove childs
// take each circle, calc its influence over all units
// now we have unit areas
struct circle {
	int x;
	int y;
};
typedef struct circle circle;

bool grid[50000][50000];
map <int, circle> circles;

// makes a circle
circle make_circle(int x, int y){
	circle c;
	c.x = x;
	c.y = y;
	return c;
}

int main(){
	int t, i, n, q, x, y, r, x1, y1, x2, y2;
	s(n); s(q);

	for (i=0; i<n; i++){
		scanf("%d %d %d", &x, &y, &r);
		circles.insert(make_pair(r, make_circle(x, y)));
	}

	// fill unit areas
	// create super array

	while (q--){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%lf\n", 2.3);
	}

	return 0;
}