#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000000
#define mdd(a) ((a)%MODULO)

/*
for m columns no of ways - 2m c m
	For m sum ways - 2m-1 c m
	For m-1 sum ways - 2m-2 c m-1
	For m-2 sum ways - 2m-3 c m-2
	......

Now to manage the rows.
	for n=1, ans1 = w0 + w1 + w2 ... wm
	for n=2, ans2 = wm * (ans1) + wm-1 * (ans1 - wm) .... 
*/

ll inv[2001];
//http://codeforces.com/blog/entry/5457?#comment-106714
void mulinv_init(){
	ll i;
	ll p = MODULO;
	inv[1] = 1;
	for (i=2; i<=2000; ++i){
		inv[i] = (p - ((p/i) * inv[p%i]) % p) % p;
		printf("%d %d\n", i, inv[i]);
	}
}

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int main(){
	int t, i, n, m, j;
	//ios_base::sync_with_stdio(0);
	//cin >> t;
	scanf("%d", &t);
	ll rowarrbs[2001], rowarr[2001], a, b, prev, prev2, bk;
	mulinv_init();

	while (t--){
		//cin >> n >> m;
		//printf("h1\n");
		scanf("%d %d", &n, &m);

		a = m-1; b = 0; // for w0
		rowarrbs[0] = 1;
		rowarr[0] = 1;
		prev = 0;
		// file last row
		for (i=1; i<=m; i++){
			a++; b++;
			//printf("h1 %d %d %d\n", a, b, inv[2]);
			rowarrbs[i] = mdd( mdd(rowarrbs[i-1] * a) * inv[b] );
			//printf("h %d\n", rowarrbs[i]);
			prev += rowarrbs[i];
			rowarr[i] = rowarrbs[i];
		}
		prev %= MODULO;
		
		// calc for n
		for (i=2; i<=n; i++){
			prev2 = 0;
			for (j=m; j>=0; j--){
				bk = rowarr[j];
				rowarr[j] = mdd( rowarrbs[j] * prev );
				prev = mdd( (prev+MODULO) - bk );
				prev2 += rowarr[j];
			}
			prev = mdd(prev2);
		}

		// o/p the result
		// cout << prev << endl;
		printf("%d\n", prev);
	}
	return 0;
}