#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define d(a) printf(">>> %d\n", a)
#define dl(a) printf(">>> %lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll arr[500][500];
ll horiz[500];
ll vert[500];
int p;
vector<int> v;
int n;


ll sum_arr(ll * sarr, int l, int r){
	int i;
	ll sum=0;
	for (i=l; i<=r; i++) sum += sarr[i];
	return sum;
}

void doStuff(ll * sarr, ll lmt){
	int i, j;
	ll csum;
	v.clear();
	vector<int>::iterator vit, max_it, tit;
	// initial divs
	v.push_back(0);
	for (i=0; i<n; i++){
		csum = 0;
		for (j=i; j<n; j++){
			csum += sarr[j];
			if (csum >= lmt){  // eq important if max num is super high
				if (j < (n-1))
					v.push_back(j+1);
				break;
			}
		}
		i = j;
	}
	v.push_back(n);

	// fine grain
	int remn = p - v.size() - 1 + 2, prev, max_ind;
	ll max_sum, tmx, loc_sum;
	int a, b;

	// printf("\n");
	// for (vit = v.begin(); vit != v.end(); vit++){
	// 	printf("%d ", *vit);
	// }
	// printf("\n");

	while (remn > 0){
		// find max
		vit = v.begin();
		vit++;
		max_sum = 0; prev = 0;
		for (; vit != v.end(); vit++){
			tmx = sum_arr(sarr, prev, *vit - 1);
			if (tmx > max_sum){
				max_sum = tmx;
				max_it = vit;
			}
			prev = *vit;
		}
		// break into two half
		tit = max_it-1;
		tmx = max_sum / 2;
		loc_sum = 0;
		a = *tit; b = *max_it;

		if ( (b - a) == 1 ){ // edge case, can't break
			sarr[a] = 0;
			continue;
		}

		for (i=a; i<b; i++){
			loc_sum += sarr[i];
			if (loc_sum > tmx){ // half..
				if (i == a)
					v.insert(max_it, i+1);
				else
					v.insert(max_it, i);
				break;
			}
		}

		remn --;
	}
}


int main(){
	int t, i, j;
	s(n); s(p);
	ll mx=0, sum=0;

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			scanf("%lld", &arr[i][j]);
			mx = max(mx, arr[i][j]);
			sum += arr[i][j];
		}
	}

	fill_n(horiz, 500, 0);
	fill_n(vert, 500, 0);
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			horiz[i] += arr[i][j];
			vert[i] += arr[j][i];
		}
	}

	vector<int>::iterator vit;
	// ll lmt = max(mx, sum / (ll) p);
	ll lmt = sum / (ll) p;

	doStuff(horiz, lmt);
	for (vit = v.begin(); vit != v.end(); vit++){
		if (*vit != 0 && *vit != n)
			printf("%d ", *vit);
	}
	printf("\n");

	doStuff(vert, lmt);
	for (vit = v.begin(); vit != v.end(); vit++){
		if (*vit != 0 && *vit != n)
			printf("%d ", *vit);
	}
	printf("\n");


	// when grid done, get the max cell, the change grid 
	return 0;
}