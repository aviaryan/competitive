#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%llu\n", a)
using namespace std;
#define ACCLIMIT 1e30

typedef unsigned long long ull;
typedef long long ll;

ull prds[100000+1];
vector<int> incl[100000+1];
bool heads[100000+1];
long double fdig[100000+1];

// shapes the double to a smaller value
double shape(double d){
	while (d>ACCLIMIT)
		d /= 1e3;
	return d;
}

ll PowMod(int bs, int n){
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
	int t, i, n, j, k, q;

	s(n);
	ull arr[n];
	fill_n(prds, n+1, 1);
	fill_n(fdig, n+1, 1.0);
	// get input
	for (i=0; i<n; i++)
		scanf("%llu", &arr[i]);
	fill_n(heads, n, false);

	// pre-process
	queue <int> que;
	for (i=1; i<n; i++){
		if (heads[i] == true)
			continue;
		que.push(i);
		while (!que.empty()){
			k = que.front();
			heads[k] = true;
			que.pop();
			if (k*2 < n)
				que.push(k*2);
			for (j=k; j<n; j+=(2*k)){
				incl[j].push_back(k);
				prds[k] = m(prds[k]*arr[j]);
				fdig[k] = shape(fdig[k] * (long double) arr[j]);
			}
		}
	}

	// get queries
	s(q);
	int op, pi, r;
	ull f, ans, div;
	double fd;
	vector<int>::iterator vi;

	while (q--){
		s(op);
		if (op == 1){
			scanf("%d %llu", &pi, &f);
			pi--;
			div = PowMod(arr[pi], MODULO-2);
			for (vi = incl[pi].begin(); vi != incl[pi].end(); vi++){
				prds[*vi] = m(prds[*vi] * div); // remove old
				prds[*vi] = m(prds[*vi] * f); // add new
				fdig[*vi] = shape(fdig[*vi] * (long double) f); // first incr
				fdig[*vi] = shape(fdig[*vi] / (long double) arr[pi]); // then reduce
			}
			arr[pi] = f;
		} else {
			s(r);
			ans = arr[0];
			fd = ans;
			if (r < n){
				while (r < n){
					fd = shape(fdig[r] * (long double) fd);
					ans = m(ans * prds[r]);
					r += r;
				}
			}
			while (fd >= 10)
				fd /= 10;
			printf("%d %llu\n", (int) fd, ans);
		}
	}

	return 0;
}