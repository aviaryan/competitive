#include "bits/stdc++.h"
#define MODULO 1000000007LL
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define LT 100000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


ll facs[LT+1]; //, divmods[LT+1];
int arr[100000], arr2[100000], n;
int testc;

void xprintf(ll d){
	if (testc==0)
		printf("%lld", d);
	else
		printf("%lld\n", d);
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

void init(){
	ll i = 1;
	facs[0] = 1;
	for (i=1; i<=LT; i++){
		facs[i] = m(i * facs[i-1]);
	}
}

ll getp(int * arrp, int num){
	// http://learnhub.com/lesson/5333-shortcut-method-to-find-rank-of-a-given-word : thanks
	// red black trees - count subs in nodes
	int i;
	list <int> ls;
	list <int>::iterator iterarr[num+1];

	for (i=num; i>0; i--){
		ls.push_front(i);
		iterarr[i] = ls.begin();
	}

	ll rank = 0;
	num--;
	for (i=0; i<num; i++){
		rank = m(rank + m( (ll) distance(ls.begin(), iterarr[arrp[i]]) * facs[num-i] ));
		ls.erase(iterarr[arrp[i]]);
	}
	return m(rank+1);
}

void solvenk(){
	int i;
	int fe = arr2[0];
	for (i=0; i<n; i++)
		if (arr[i] == fe) break;
	fe = i;
	for (i=0; i<n; i++){
		if (arr2[i] != arr[fe]){
			xprintf(-1);
			return;
		}
		fe = (fe+1)%n;
	}
	xprintf(arr2[0]);
	return;
}


ll getrank(int * ar, int size){
	// find real pos in set of perms . modulo messes the whole shit up
	int nar[size], dar[size], i, j;
	for (i=0; i<size; i++){
		nar[i] = ar[i];
		dar[i] = ar[i];
	}
	sort(nar, nar+size);
	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			if (dar[j] == nar[i]){
				dar[j] = i+1;
				break;
			}
	}
	
	return getp(dar, size);
}

bool isinsame(ll a, ll b){
	if (a%2) a+=1;
	if (b%2) b+=1;
	return ((a/2)%2 == (b/2)%2);
}

bool isinsame(int * ar1, int * ar2){
	ll r1 = getrank(ar1, 4);
	ll r2 = getrank(ar2, 4);
	// printf("%lld %lld\n", r1, r2);
	return isinsame(r1, r2);
}

ll realpos(int * ar){
	ll rank = getrank(ar, 6);
	if (rank % 24 != 0)
		rank = ((ll) (rank/24))*24 + 24;
	//printf("%lld\n", rank);
	return (rank/24) % 2;
}


int main(){
	int i, k;
	s(testc);
	ll mulf, posn, posres, mulfres, xposn, xposres;
	bool cmp, sameseq, wrong1, wrong2;
	init();

	while (testc--){
		scanf("%d %d", &n, &k);
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		for (i=0; i<n; i++)
			scanf("%d", &arr2[i]);

		printf("%lld %lld\n", getp(arr,n), getp(arr2,n));

		if (n == k){
			solvenk();
		} else if (k%2 == 0) {
			posres = getp(arr2, n);
			xprintf(posres);
		} else {

			if (n <= 6){
				posn = getp(arr, n);
				xposn = (posn == 0) ? MODULO : posn;
				wrong1 = ((arr[n-2] < arr[n-1]) && (xposn%2 == 0)) || ((arr[n-2] > arr[n-1]) && (xposn%2 == 1));
			}
			if (n>6)
				mulf = realpos(&arr[n-6]);
			else
				mulf = (ll) ceil(posn / 24.0) % 2;

			posres = getp(arr2, n);
			xposres = (posres == 0) ? MODULO : posres;
			// xprintf(posres);
			wrong2 = ((arr2[n-2] < arr2[n-1]) && (xposres%2 == 0)) || ((arr2[n-2] > arr2[n-1]) && (xposres%2 == 1));
			if (n>6)
				mulfres = realpos(&arr2[n-6]);
			else
				mulfres = (ll) ceil(posres / 24.0) % 2;

			// printf("%lld %lld\n", mulf, mulfres);

			if (n>4)
				sameseq = isinsame(&arr[n-4], &arr2[n-4]);
			else
				sameseq = isinsame(posn, posres);
			//printf("%u %lld %lld\n", sameseq, posn, posres);
			posres = xposres;
			if (wrong2) posres += MODULO;
			if (posres % 2) posres += 1;

			if (mulf == mulfres){
				cmp = (arr[n-2] < arr[n-1]);
				if (!sameseq) cmp = !cmp;
				if ((arr2[n-2] < arr2[n-1]) == cmp)
					xprintf(m(posres/2));
				else
					xprintf(-1);
			} else {
				cmp = (arr[n-2] < arr[n-1]);
				if (!sameseq) cmp = !cmp;
				if ((arr2[n-2] < arr2[n-1]) != cmp)
					xprintf(m(posres/2));
				else
					xprintf(-1);
			}

		}
	}

	return 0;
}

/*
1
6 3
2 1 4 5 3 6
1 3 2 4 5 6
*/

/*
2
4 2
2 4 3 1
1 2 4 3
3 3
1 2 3
1 3 2
*/

/*
2
16 9
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2
16 9
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 16 15 14 13 12 11 10 9 8 7 6 5 4 2 3
*/