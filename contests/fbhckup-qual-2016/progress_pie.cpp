#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define PI 3.14159265
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, cas = 0;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int p, x, y;
	double ang, qang;
	bool in_cir, in_ang;

	while (t--){
		cas++;
		cin >> p >> x >> y;
		x -= 50; y -= 50;
		in_cir = ((x*x + y*y) <= 2500);
		// spl case, infi
		if (x == 0){
			if (y < 0){
				ang = 180;
			} else if (y > 0) {
				ang = 0;
			} else {
				ang = -1;
			}
		// spl case 0
		} else if (y == 0){
			if (x > 0){
				ang = 90;
			} else if (x < 0){
				ang = 270;
			} else {
				ang = -1;
			}
		// normal case
		} else {
			ang = atan((double) y / (double) x) * 180.0 / PI; // whats the range here
			if (x < 0){
				ang = 270.0 - ang;
			} else {
				if (ang < 0)  // range of atan is -90, 90
					ang = 90 + -1*ang;
			}
		}
		// answer
		if (p == 0){
			in_ang = false;
		} else if (ang == -1){
			in_ang = true;
		} else {
			// cout << "d" << ang << endl;
			qang = ((double) p / 100.0) * 360.0;
			in_ang = (ang <= qang);
		}
		// print
		cout << "Case #" << cas << ": ";
		if (in_cir && in_ang){
			cout << "black" << endl;
		} else {
			cout << "white" << endl;
		}
	}

	return 0;
}