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

// CUSTOM TYPES

typedef struct {
	int five;
	int two;
} num;

// DECLARATIONS

num farr[100000];
num fbSeries[100000 + 1];

// ACC FUNCTIONS

num calcFactors(int k){
	num s;
	s.five = 0; s.two = 0;
	while (k % 2 == 0){
		k /= 2;
		s.two++;
	}
	while (k % 5 == 0){
		k /= 5;
		s.five++;
	}
	return s;
}

void makeBS(){
	for (int i=1; i<=100000; i++)
		fbSeries[i] = calcFactors(i);
}

void updateX(int l, int r, int x){
	num factor = calcFactors(x);
	for (int i=l; i<=r; i++){
		farr[i].five += factor.five;
		farr[i].two += factor.two;
	}
}

void updateY(int l, int r, int y){
	int i, ct=1;
	num factor = calcFactors(y), temp;
	for (i=l; i<=r; i++){
		temp = fbSeries[ct];
		temp.five += factor.five;
		temp.two += factor.two;
		farr[i] = temp;
		ct++;
	}
}

int getAns(int l, int r){
	num factor = calcFactors(1); // 0 0
	for (int i=l; i<=r; i++){
		factor.two += farr[i].two;
		factor.five += farr[i].five;
	}
	return min(factor.two, factor.five);
}

// MAIN

int main(){
	int t, i, n, m, k, op, l, r, param, ans;
	s(t);
	makeBS();

	while (t--){
		scanf("%d %d", &n, &m);
		ans = 0;
		for (i=0; i<n; i++){
			scanf("%d", &k);
			farr[i] = calcFactors(k);
		}
		for (i=0; i<m; i++){
			scanf("%d", &op);
			if (op < 3){
				scanf("%d %d %d", &l, &r, &param);
				if (op == 1)
					updateX(l-1, r-1, param);
				else
					updateY(l-1, r-1, param);
			} else {
				scanf("%d %d", &l, &r);
				ans += getAns(l-1, r-1);
			}
		}
		p(ans);
	}

	return 0;
}