#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define LT 100000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// CUSTOM TYPES

typedef struct {
	int five;
	int two;
	int startY;
	ll sum_five;
	ll sum_two;
} seg;

// DECLARATIONS

int arrFive[LT];
int arrTwo[LT];

int fbSeriesFive[LT + 1];
int fbSeriesTwo[LT + 1];

int fbSeriesSumFive[LT + 1];
int fbSeriesSumTwo[LT + 1];

seg divs[317];  // ceil sqrt LT
int divSize, divCount, n;

int globFive, globTwo;

// ACC FUNCTIONS

void calcFactors(int k){
	globTwo = 0; globFive = 0;
	while (k % 2 == 0){
		k /= 2;
		globTwo++;
	}
	while (k % 5 == 0){
		k /= 5;
		globFive++;
	}
}

void makeBasicSeries(){
	fbSeriesSumFive[0] = 0;
	fbSeriesSumTwo[0] = 0;
	for (int i=1; i<=LT; i++){
		calcFactors(i);
		fbSeriesTwo[i] = globTwo;
		fbSeriesFive[i] = globFive;
		fbSeriesSumFive[i] = fbSeriesFive[i] + fbSeriesSumFive[i-1];
		fbSeriesSumTwo[i] = fbSeriesTwo[i] + fbSeriesSumTwo[i-1];
	}
}

// FUNCTIONS

void initDivs(){
	seg tDev;
	tDev.five = 0; tDev.two = 0;
	tDev.startY = -1;
	for (int i=0; i<divCount; i++){
		divs[i] = tDev;
	}
}

void makeSegs(){
	int i, j, five, two;
	for (i=0; i<n; i+=divSize){
		five = 0; two = 0;
		for (j=i; j<(i+divSize) && j<n; j++){
			five += arrFive[j];
			two += arrTwo[j];
		}
		divs[i/divSize].sum_five = five;
		divs[i/divSize].sum_two = two;
	}
}

void dissolveY(int l){
	int divId = l/divSize;
	if (divs[divId].startY == -1)
		return;
	// printf("> diss y\n");
	int startY = divs[divId].startY; 
	int count=0;
	// update things
	for (int i=l; i<(l+divSize) && i<n; i++){
		arrFive[i] = fbSeriesFive[startY+count];
		arrTwo[i] = fbSeriesTwo[startY+count];
		count++;
	}
	// reset
	divs[divId].startY = -1;
}

void dissolveX(int l){
	int divId = l/divSize;
	int five = divs[divId].five;
	int two = divs[divId].two;
	if (five == 0 && two == 0)
		return;
	// printf("> diss x\n");
	for (int i=l; i<(l+divSize) && i<n; i++){
		arrFive[i] += five;
		arrTwo[i] += two;
	}
	// reset
	divs[divId].five = 0;
	divs[divId].two = 0;
}

void updateX(int l, int r, int x){
	int istart = (l/divSize) * divSize, count, i;
	calcFactors(x);
	int five = globFive, two = globTwo;
	// first half full
	if (l > istart){
		dissolveY(istart);
		for (i=l; i<(istart+divSize) && i<=r; i++){
			arrFive[i] += five;
			arrTwo[i] += two;
		}
		count = min(r-l+1, (istart+divSize)-l);
		divs[istart/divSize].sum_five += (ll) (count * five);
		divs[istart/divSize].sum_two += (ll) (count * two);
		// increment istart
		istart+=divSize;
	}
	// mids
	for (i=istart; i<=r; i+=divSize){
		if (r >= (i+divSize-1)){
			divs[i / divSize].five += five;
			divs[i / divSize].two += two;
			divs[i / divSize].sum_five += (ll) (divSize * five);
			divs[i / divSize].sum_two += (ll) (divSize * two);
		} else {
			dissolveY(i);
			int lt = i;
			for (;i<=r; i++){
				arrFive[i] += five;
				arrTwo[i] += two;
			}
			divs[lt / divSize].sum_five += (ll) ((r-lt+1) * five);
			divs[lt / divSize].sum_two += (ll) ((r-lt+1) * two);
			break;
		}
	}
}

void updateY(int l, int r, int y){
	int istart = (l/divSize) * divSize, count, i;
	calcFactors(y);
	int five = globFive, two = globTwo;
	int oldFive, oldTwo;
	int yc = 1;
	// first half full
	if (l > istart){
		dissolveY(istart);
		dissolveX(istart);
		oldTwo = 0; oldFive = 0;
		for (i=l; i<(istart+divSize) && i<=r; i++){
			oldFive += arrFive[i]; oldTwo += arrTwo[i];
			arrFive[i] = fbSeriesFive[yc] + five;
			arrTwo[i] = fbSeriesTwo[yc] + two;
			yc++;
		}
		count = min(r-l+1, (istart+divSize)-l);
		divs[istart/divSize].sum_five += (ll) (fbSeriesSumFive[yc-1] + count*five - oldFive);
		divs[istart/divSize].sum_two += (ll) (fbSeriesSumTwo[yc-1] + count*two - oldTwo);
		// increment istart
		// printf("> hi divSize =%d sum_two = %d sum_five=%d \n", divSize, divs[istart/divSize].sum_two, divs[istart/divSize].sum_five);
		istart+=divSize;
	}
	// mids
	for (i=istart; i<=r; i+=divSize){
		if (r >= (i+divSize-1)){
			divs[i/divSize].startY = yc;
			divs[i/divSize].five = five;
			divs[i/divSize].two = two;
			divs[i/divSize].sum_five = (ll) (fbSeriesSumFive[yc+divSize-1] - fbSeriesSumFive[yc-1] + divSize*five);
			divs[i/divSize].sum_two = (ll) (fbSeriesSumTwo[yc+divSize-1] - fbSeriesSumTwo[yc-1] + divSize*two);
			yc += divSize;
			// printf("> in here\n");
		} else {
			// printf("> y last update\n");
			dissolveY(i);
			dissolveX(i);
			int lt = i;
			oldTwo = 0; oldFive = 0;
			for (;i<=r; i++){
				oldFive += arrFive[i]; oldTwo += arrTwo[i];
				arrFive[i] = fbSeriesFive[yc] + five;
				arrTwo[i] = fbSeriesTwo[yc] + two;
				yc++;
			}
			count = (r-lt+1);
			divs[lt/divSize].sum_five += (ll) (fbSeriesSumFive[yc-1] - fbSeriesSumFive[yc-1-count] + count*five - oldFive);
			divs[lt/divSize].sum_two += (ll) (fbSeriesSumTwo[yc-1] - fbSeriesSumTwo[yc-1-count] + count*two - oldTwo);
			break;
		}
	}
}

ll getAns(int l, int r){
	int istart = (l/divSize) * divSize, count, i;
	ll five = 0; ll two = 0;
	// first half full
	if (l > istart){
		dissolveY(istart);
		for (i=l; i<(istart+divSize) && i<=r; i++){
			five += arrFive[i];
			two += arrTwo[i];
		}
		count = min(r-l+1, (istart+divSize)-l);
		five += (ll) (count * divs[istart / divSize].five); 
		two += (ll) (count * divs[istart / divSize].two);
		// increment istart
		istart+=divSize;
	}
	// mids
	for (i=istart; i<=r; i+=divSize){
		if (r >= (i+divSize-1)){
			five += divs[i / divSize].sum_five;
			two += divs[i / divSize].sum_two;
		} else {
			dissolveY(i);
			int lt = i;
			for (;i<=r; i++){
				five += (ll) arrFive[i];
				two += (ll) arrTwo[i];
			}
			count = r-lt+1;
			five += (ll) (count * divs[lt / divSize].five); 
			two += (ll) (count * divs[lt / divSize].two);
			break;
		}
	}
	return min(five, two);
}

// MAIN

int main(){
	int t, i, m, temp, l, r, param, op;
	s(t);
	ll ans;
	makeBasicSeries();

	while (t--){
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++){
			scanf("%d", &temp);
			calcFactors(temp);
			arrFive[i] = globFive;
			arrTwo[i] = globTwo;
		}
		// pre-process
		divSize = sqrt(n);
		divCount = ceil((double) n / (double) divSize);
		initDivs();
		makeSegs();
		// answer queries
		ans = 0;
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
		printf("%lld\n", ans);
	}

	return 0;
}