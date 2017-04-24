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

int k, n; 
char str[13];
double xs[36], ys[36];
bool avlbl[36][12];
bool kind[12];

int sorts[36][36];
int lc;

double min_dist;
double sort_x, sort_y;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int compare(const void * a, const void * b){
	const int *ia = (const int *) a;
	const int *ib = (const int *) b;
	return ( dist(sort_x, sort_y, xs[*ia], ys[*ia])  -  dist(sort_x, sort_y, xs[*ib], ys[*ib]) );
}

void brute(int pos, double dis, bitset<12> done, bitset<36> visited){
	int i, j, ir;
	if (done.count() == k){
		dis += dist(xs[pos], ys[pos], 0, 0);
		min_dist = min(dis, min_dist);
		return;
	}
	if (dis >= min_dist){
		return;
	}

	if (lc > 1000000 && min_dist < (MODULO-1)){
		return;
	}

	if (sorts[pos][0] == -1){
		int arr[n];
		for (i=0; i<n; i++) arr[i] = i;
		sort_x = xs[pos]; sort_y = ys[pos];
		qsort(arr, n, sizeof(int), compare);
		for (i=0; i<n; i++)
			sorts[pos][i] = arr[i];
	}
	lc++;

	for (i=0; i<n; i++){
		ir = sorts[pos][i];
		if (!visited[36-ir-1]){
			bitset <36> newv (visited);
			newv.set(36-ir-1, 1);
			bitset <12> newd (done);
			for (j=0; j<k; j++)
				if (avlbl[ir][j])
					newd.set(12-j-1, 1);
			if (newd.count() <= done.count())  // if no change
				continue;
			brute(ir, dis + dist(xs[ir], ys[ir], xs[pos], ys[pos]), newd, newv);
		}
	}
}

int main(){
	int t, i, j, ir;
	ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		s(n); s(k);
		for (i=0; i<n; i++){
			scanf("%lf %lf", &xs[i], &ys[i]);
		}
		fill_n(kind, 12, false);
		for (i=0; i<n; i++){
			scanf("%s", str);
			for (j=0; j<k; j++){
				avlbl[i][j] = (str[j] == '1') ? true : false;
				if (str[j] == '1') 
					kind[j] = true;
			}
		}
		// -1 case
		bool st = false;
		for (j=0; j<k; j++){
			if (!kind[j]) st = true;
		}
		if (st){
			printf("-1\n");
			continue;
		}
		// end -1 case
		min_dist = 1e9; lc=0;

		int arr[n];
		for (i=0; i<n; i++) arr[i] = i;
		sort_x = 0; sort_y = 0;
		qsort(arr, n, sizeof(int), compare);

		//printf("first %d\n", arr[0]);
		// sortings saver
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				sorts[i][j] = -1;

		// brute
		for (i=0; i<n; i++){
			ir = arr[i];
			bitset <36> newv; newv.reset();
			newv.set(36-ir-1, 1);
			bitset <12> newd; newd.reset();
			for (j=0; j<k; j++)
				if (avlbl[ir][j])
					newd.set(12-j-1, 1);
			if (newd.count() == 0) continue;
			brute(ir, dist(xs[ir], ys[ir], 0, 0), newd, newv);
		}

		printf("%.8lf\n", min_dist);
	}

	return 0;
}