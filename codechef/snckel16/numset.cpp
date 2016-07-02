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
	int t, i, n, j, keep;
	s(t);

	int sieve[1001];
	bool primes[1001];
	primes[1] = true;
	int grp=0;
	fill_n(sieve, 1001, 0);

	for (i=2; i<=1000; i++){
		if (sieve[i] != 0)
			continue;
		grp++;
		for (j=i; j<=1000; j+=i){
			sieve[j] = grp;
			primes[j] = false;
		}
		primes[i] = true;
	}

	set <int> st;
	while (t--){
		s(n);
		keep = 0;
		st.clear();
		for (i=0; i<n; i++){
			s(j);
			if (j == 1)
				keep++;
			else {
				if (st.find(sieve[j]) == st.end()){
					st.insert(sieve[j]);
					keep++;
				}
			}
		}
		p(keep);
	}

	return 0;
}