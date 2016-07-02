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

void printdir(int z, int op){
	if (op == 1) printf("%d NE\n", z);
	else if (op == 2) printf("%d NW\n", z);
	else if (op == 3) printf("%d SW\n", z);
	else printf("%d SE\n", z);
}

int main(){
	int t, i, n;
	s(t);
	int xs[100000], ys[100000];
	int tl, tr, bl, br, ct, cb, ml, mr;

	while (t--){
		s(n);

		ct = -MODULO; cb = MODULO; ml = MODULO; mr = -MODULO;
		for (i=0; i<n; i++){
			scanf("%d %d", &xs[i], &ys[i]);

			if ( ys[i] > ct ){
				tl = i; tr = i; ct = ys[i];
			} else if (ys[i] == ct){
				if (xs[i] < xs[tl])
					tl = i;
				if (xs[i] > xs[tr])
					tr = i;
			}
			if ( ys[i] < cb ){
				bl = i; br = i; cb = ys[i];
			} else if (ys[i] == cb){
				if (xs[i] < xs[bl])
					bl = i;
				if (xs[i] > xs[br])
					br = i;
			}
			ml = min( ml, xs[i] );
			mr = max( mr, xs[i] );
		}

		// sidemost cases - one hit done
		if ( xs[tl] == ml ){
			printf("1\n");
			printdir(tl+1, 4);
			continue;
		} else if ( xs[tr] == mr ){
			printf("1\n");
			printdir(tr+1, 3);
			continue;
		} else if ( xs[bl] == ml ){
			printf("1\n");
			printdir(bl+1, 1);
			continue;
		} else if ( xs[br] == mr ){
			printf("1\n");
			printdir(br+1, 2);
			continue;
		}

		// opposite corner entropy
		if ( xs[tl] <= xs[br] ){
			printf("2\n");
			printdir(tl+1, 4);
			printdir(br+1, 2);
		} else if ( xs[tr] >= xs[bl] ){
			printf("2\n");
			printdir(tr+1, 3);
			printdir(bl+1, 1);
		} else {
			assert(0);
		}
	}

	return 0;
}