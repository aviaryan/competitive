#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%llu", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, maxl;
ull arr[30];
ull muls[30];
ll ct;
ull k;

void recurse(int i, ull cp){
	if (cp > k){
		ct--;
		return;
	}
	if (i == n)
		return;

	long double cur;
	cur = (long double) k / (long double) cp;
	ull curl = cur;
	if (curl >= arr[i]){
		ct++;
		recurse(i+1, cp * arr[i]);
	}
	recurse(i+1, cp);
}

void recurse_back(int i, ull cp){
	if (cp > k){
		ct--;
		return;
	}
	if (i == -1)
		return;
	// jump
	ull cur = k / cp;
	if (i < maxl && cur >= muls[i]){
		// printf("why %d %llu\n", i, cp);
		ct += pow(2, i + 1) - 1;
		return;
	}
	// normal
	if (cur >= arr[i]){
		ct++;
		recurse_back(i-1, cp * arr[i]);
	}
	recurse_back(i-1, cp);	
}

int main(){
	int i;
	s(n); sl(k);
	ct = 0;

	for (i=0; i<n; i++)
		sl(arr[i]);
	sort(arr, arr+n);

	ull prod = 1, cur;
	for (i=0; i<n; i++){
		cur = k / prod;
		if (cur >= arr[i])
			prod = prod * arr[i];
		else
			break;
		if (prod > k) break;
		muls[i] = prod;
	}
	// easy , also reqd for ct += pow.. -1 step
	if (i == n){
		printf("%d\n", (1 << n) - 1);
		return 0;
	}
	maxl = i;

	recurse_back(n-1, 1);
	// recurse(0, 1);
	printf("%lld\n", ct);

	return 0;
}