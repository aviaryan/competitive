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
	int t, i, n;
	s(n);
	int arr[n]; 
	int sorted[n];

	for (i=0; i<n; i++){
		scanf("%d", &sorted[i]);
		arr[i] = sorted[i];
	}

	sort(sorted, sorted+n);
	vector <int> v;
	vector <int>::iterator vit;

	// check for swap and already sorted
	int diff = 0;
	for (i=0; i<n; i++)
		if (sorted[i] != arr[i]){
			diff++;
			v.push_back(i);
		}

	if (diff == 0){
		printf("yes\n");
		return 0;
	} else if (diff == 2){
		if ( (arr[v[0]] == sorted[v[1]]) && (arr[v[1]] == sorted[v[0]]) ){
			printf("yes\nswap %d %d", v[0]+1, v[1]+1);
			return 0;
		}
	}

	// check for reverse and not possible
	vit = v.begin();
	int sp = *vit;
	int tsp = sp;
	bool fail = false;
	bool mid_elem = false;
	for (++vit; vit != v.end(); vit++){
		if ((*vit - tsp) == 1)
			tsp++;
		else if (mid_elem == false && (*vit - tsp) == 2){  // as all di's are distinct so one equals only possible
			tsp = *vit;
			mid_elem = true;
		} else {
			fail = true;
			break;
		}
	}
	// check correct reverse
	int l = sp, r = tsp;
	if (!fail){
		for (i=0; i<(tsp-sp+1); i++){
			if (arr[l] != sorted[r]){
				fail = true;
				break;
			}
			l++; r--;
		}
	}
	// final output
	if (fail){
		printf("no\n");
		return 0;
	} else {
		printf("yes\nreverse %d %d", sp+1, tsp+1);
	}


	return 0;
}