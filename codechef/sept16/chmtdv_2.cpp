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
ll h_sum_arr[500][500];
ll sumarr[500][500];
int p;
vector<int> v;
vector <int> hzCuts;
vector <int> vtCuts;
int n;


// sum array from l to r
ll sum_arr(ll * sarr, int l, int r){
	int i;
	ll sum=0;
	for (i=l; i<=r; i++) sum += sarr[i];
	return sum;
}

// blah
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

// make the horizontal sum arr
void make_hsum_arr(){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if (j == 0)
				h_sum_arr[i][j] = arr[i][j];
			else
				h_sum_arr[i][j] = arr[i][j] + h_sum_arr[i][j-1];
		}
	}
}

// make matrix sum arr
void make_matrix_sum_arr(){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if (i == 0)
				sumarr[i][j] = h_sum_arr[i][j];
			else
				sumarr[i][j] = sumarr[i-1][j] + h_sum_arr[i][j];
		}
	}
}

// outputs the cuts
void printAns(vector <int> vec){
	vector<int>::iterator vit;
	for (vit = vec.begin(); vit != vec.end(); vit++){
		if (*vit != 0 && *vit != n)
			printf("%d ", *vit);
	}
	printf("\n");
}

// get sum of sub-matrix
ll mx_sum(int h1, int h2, int v1, int v2){
	ll sum;
	sum = sumarr[h2-1][v2-1];
	if (h1 != 0) sum -= sumarr[h1-1][v2-1];
	if (v1 != 0) sum -= sumarr[h2-1][v1-1];
	if (h1 != 0 && v1 != 0) sum += sumarr[h1-1][v1-1];
	return sum;
}

// see all vert cuts in a row
ll max_grid_vert(int hzPrev, int h2){
	vector <int>::iterator vit1;
	int vtPrev = 0;
	ll mx = 0, tmx;
	for (vit1 = vtCuts.begin(); vit1 != vtCuts.end(); vit1++){
		tmx = mx_sum(hzPrev, h2, vtPrev, *vit1);
		if (tmx > mx)
			mx = tmx;
		vtPrev = *vit1;
	}
	return mx;
}

// see all horz cuts in a col
ll max_grid_horz(int vtPrev, int v2){
	vector <int>::iterator vit1;
	int hzPrev = 0;
	ll mx = 0, tmx;
	for (vit1 = hzCuts.begin(); vit1 != hzCuts.end(); vit1++){
		tmx = mx_sum(hzPrev, *vit1, vtPrev, v2);
		if (tmx > mx) 
			mx = tmx;
		hzPrev = *vit1;
	}
	return mx;
}


// optimize grid
bool optGrid(){
	vector <int>::iterator vit1, vit2;
	int hzPrev = 0, vtPrev;
	int mxH1, mxH2, mxV1, mxV2;
	ll mx = 0, tmx;
	// find max
	for (vit1 = hzCuts.begin(); vit1 != hzCuts.end(); vit1++){
		vtPrev = 0;
		for (vit2 = vtCuts.begin(); vit2 != vtCuts.end(); vit2++){
			tmx = mx_sum(hzPrev, *vit1, vtPrev, *vit2);
			if (tmx > mx){
				mxH1 = hzPrev; mxH2 = *vit1; mxV1 = vtPrev; mxV2 = *vit2; mx = tmx;
			}
			vtPrev = *vit2;
		}
		hzPrev = *vit1;
	}
	// manipulate grids
	int t1, t2, type = 0;
	ll mn = mx, t_min;

	if (mxH2 - mxH1 > 1){
		if (mxH1 != 0){
			t1 = *(find(hzCuts.begin(), hzCuts.end(), mxH1) - 1);
			t_min = max(mx_sum(mxH1+1, mxH2, mxV1, mxV2), max_grid_vert(t1, mxH1+1));
			if (t_min < mn) type = 1; mn = t_min;
		}
		if (mxH2 != n){
			t1 = *(find(hzCuts.begin(), hzCuts.end(), mxH2) + 1);
			t_min = max(mx_sum(mxH1, mxH2-1, mxV1, mxV2), max_grid_vert(mxH2-1, t1));
			if (t_min < mn) type = 2; mn = t_min;
		}
	}
	if (mxV2 - mxV1 > 1){
		if (mxV1 != 0){
			t1 = *(find(vtCuts.begin(), vtCuts.end(), mxV1) - 1);
			t_min = max(mx_sum(mxH1, mxH2, mxV1+1, mxV2), max_grid_horz(t1, mxV1+1));
			if (t_min < mn) type = 3; mn = t_min;
		}
		if (mxV2 != n){
			t1 = *(find(vtCuts.begin(), vtCuts.end(), mxV2) + 1);
			t_min = max(mx_sum(mxH1, mxH2, mxV1, mxV2-1), max_grid_horz(mxV2-1, t1));
			if (t_min < mn) type = 4; mn = t_min;
		}
	}
	// set value
	if (type == 0)
		return false;
	if (type == 1)
		*find(hzCuts.begin(), hzCuts.end(), mxH1) = mxH1+1;
	else if (type == 2)
		*find(hzCuts.begin(), hzCuts.end(), mxH2) = mxH2-1;
	else if (type == 3)
		*find(vtCuts.begin(), vtCuts.end(), mxV1) = mxV1+1;
	else if (type == 4)
		*find(vtCuts.begin(), vtCuts.end(), mxV2) = mxV2-1;
	return true;
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
	ll lmt = max(mx, sum / (ll) p);

	make_hsum_arr(); make_matrix_sum_arr();

	doStuff(horiz, lmt);
	hzCuts = v; hzCuts.erase(hzCuts.begin());

	doStuff(vert, lmt);
	vtCuts = v; vtCuts.erase(vtCuts.begin());

	// when grid done, get the max cell, the change grid
	bool st;
	for (i=0; i<300; i++){
		st = optGrid();
		if (!st) break;
	}

	printAns(hzCuts);
	printAns(vtCuts);
	return 0;
}