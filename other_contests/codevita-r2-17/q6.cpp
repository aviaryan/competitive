// prime counters

#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define ALIMIT 1000000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int factors[ALIMIT + 1];
int cp[ALIMIT + 1];
bool pc[ALIMIT + 1];
int pcSum[ALIMIT + 1];

// primes
// build the prime table
void sieve(){
	int i, j;
	fill_n(factors, ALIMIT+1, 1);
	factors[0] = -1; // not prime
	factors[1] = 0; // not prime
	// prime factors[j] == j
	for (i=2; i<=ALIMIT; i++){
		if (factors[i] != 1) continue;
		for (j=i; j<=ALIMIT; j+=i){
			if (factors[j] == 1)
				factors[j] = i;
		}
	}
}

// no of primes between 1 and N
void cpBuild(){
	int i;
	cp[1] = 0;
	for (i=2; i<=ALIMIT; i++){
		cp[i] = cp[i-1] + (factors[i] == i ? 1 : 0);
	}
}

// cp(n) is prime then n a PC
void pcBuild(){
	int i;
	for (i=1; i<=ALIMIT; i++){
		pc[i] = (factors[cp[i]] == cp[i]);
	}
}

void pcSumBuild(){
	int i;
	pcSum[0] = 0;
	pcSum[1] = 0;
	for (i=2; i<=ALIMIT; i++){
		pcSum[i] = pcSum[i-1] + (pc[i] ? 1 : 0);
	}
}

int main(){
	int t, i, l, r;
	ios_base::sync_with_stdio(0);
	cin >> t;

	sieve();
	cpBuild();
	pcBuild();
	pcSumBuild();

	while (t--){
		cin >> l >> r;
		if (l == 0) l = 1;
		cout << pcSum[r] - pcSum[l-1] << endl;
	}

	return 0;
}