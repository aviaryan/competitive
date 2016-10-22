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


pair<int, int> sarr[100000];


int compare(const void * a, const void * b){
	const pair<int,int> *ia = (const pair<int,int> *) a;
	const pair<int,int> *ib = (const pair<int,int> *) b;
	return ( ia->second < ib->second );
}

void printAns(pair<int, int> * arr, int n){
	int result[n];
	bool slot[n];

	for (int i=0; i<n; i++)
		slot[i] = false;
	for (int i=0; i<n; i++){
		for (int j=min(n, arr[i].first)-1; j>=0; j--){
			if (slot[j]==false){
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	int score = 0;
	for (int i=0; i<n; i++)
		if (slot[i])
			score += arr[result[i]].second;

	p(score);
}


int main(){
	int t, i, n, j;
	int dead, pts;
	// ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		s(n);
		for (i=0; i<n; i++){
			scanf("%d %d", &dead, &pts);
			sarr[i] = make_pair(dead, pts);
		}
		qsort(sarr, n, sizeof(pair<int,int>), compare);
		printAns(sarr, n);
	}

	return 0;
}