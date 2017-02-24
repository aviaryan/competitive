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


ll facs[LT+1];
int arr[100000], arr2[100000], n;
int bitarr[LT+1], bitcache[LT+1];
int * bit;
int testc;

// bit //

int getSum(int num, int index){
	int sum = 0;
	index++;

	while (index>0){
		sum += bit[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(int num, int index, int val){
	index++;
	while (index <= num)
	{
		bit[index] += val;
		index += index & (-index);
	}
}

void constructBIT(int num){
    for (int i=1; i<=num; i++)
        bit[i] = 0;
    for (int i=0; i<num; i++)
        updateBIT(num, i, 1);
}

void fastConstructBIT(int num){
	for (int i=0; i<=num; i++)
		bit[i] = bitcache[i];
}

// end of bit //

void xprintf(ll d){
	if (testc==0)
		printf("%lld", d);
	else
		printf("%lld\n", d);
}

void init(){
	ll i = 1;
	facs[0] = 1;
	bit = &bitcache[0];
	for (i=1; i<=LT; i++)
		facs[i] = m(i * facs[i-1]);
	constructBIT(LT);
	bit = &bitarr[0];
}

ll getp(int * arrp, int num){ // a better ds will help but anyway
	fastConstructBIT(num);
	ll rank = 0;
	int i, nx = num;
	num--;
	for (i=0; i<num; i++){
		rank = m(rank + m((ll) (getSum(nx, arrp[i]-1)-1) * facs[num-i]));
		updateBIT(nx, arrp[i]-1, -1);
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

int getSeries(int * arrp, int n){
	fastConstructBIT(n);
	int x=0, i;
	for (i=0; i<n; i++){
		x += (getSum(n, arrp[i]-1)-1);
		x %= 2;
		updateBIT(n, arrp[i]-1, -1);
	}
	return x;
}


int main(){
	int i, k;
	s(testc);
	ll mulf, posn, posres, mulfres, xposn, xposres;
	bool cmp, sameseq, wrong1, wrong2, seq2;
	init();

	while (testc--){
		scanf("%d %d", &n, &k);
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		for (i=0; i<n; i++)
			scanf("%d", &arr2[i]);

		if (n == k){
			solvenk();
		} else if (k%2 == 0) {
			posres = getp(arr2, n);
			xprintf(posres);
		} else {

			posres = getp(arr2, n);
			xposres = (posres == 0) ? MODULO : posres;
			wrong2 = ((arr2[n-2] < arr2[n-1]) && (xposres%2 == 0)) || ((arr2[n-2] > arr2[n-1]) && (xposres%2 == 1));

			sameseq = getSeries(arr, n);
			seq2 = getSeries(arr2, n);

			posres = xposres;
			if (wrong2) posres += MODULO;
			if (posres % 2) posres += 1;

			if (sameseq == seq2){
				xprintf(m(posres/2));
			} else
				xprintf(-1);
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