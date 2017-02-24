#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
using namespace std;
#define m(a) ((a)%MODULO)

typedef unsigned long long ull;
typedef long long ll;

void matrixmul22(ll *a, ll *b){
	ll r[4];
	r[0] = m( m(a[0]*b[0])+ m(a[1]*b[2]) );
	r[1] = m( m(a[0]*b[1])+ m(a[1]*b[3]) );
	r[2] = m( m(a[2]*b[0])+ m(a[3]*b[2]) );
	r[3] = m( m(a[2]*b[1])+ m(a[3]*b[3]) );
	for (int i=0; i<4; i++)
		a[i] = r[i];
}

ll FibN(ll a, ll b, ll n)
{
	ll xi[4] = {1, 1, 1, 0};
	if (n<=2)
		return n==2 ? b : a;
	n-=2;

    ll ret[4] = {1,0,0,1};
    while (n > 0){
        if (n & 1)
        	matrixmul22(ret, xi);
        matrixmul22(xi,xi);
        n >>= 1;
    }

    return m(m(ret[0]*b)+m(ret[1]*a));
}

int main(){
	ll t, i, a, b, n;
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--){
		cin >> a >> b >> n;
		cout << FibN(a, b, n+1) << endl;
	}
	return 0;
}