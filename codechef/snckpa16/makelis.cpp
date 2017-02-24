#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define ds() printf("_hi_")
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int pows[7];

int maxpower(int k){
	int i;
	for (i=0; i<7; i++){
		if (pows[i] > k)
			break; 
	}
	return i-1;
}

int main(){
	int t, i, k, j;
	s(t);
	int maxp, curp, times;
	int att[6];
	int backs[100], fwds[100];
	int backcp[100];
	int curnum, curset, len_incr, backs_p, backcp_p;
	int n;

	// int 8 ps
	pows[0] = 1;
	for (i=1; i<7; i++)
		pows[i] = 8 * pows[i-1];

	// solve
	// for (t=101; t<=100000; t++){
	// 	k=t;
	while (t--){
		s(k);
		// easy case
		if (k <= 100){
			printf("%d\n", k);
			for (i=k; i>0; i--){
				printf("%d ", i);
			}
			printf("\n");
			continue;
		}
		// mard wala case
		fill_n(att, 6, 0);
		maxp = maxpower(k);
		curp = maxp;
		times = k/pows[curp];
		att[curp] = times;
		while (k>0){
			k = k - times*pows[curp];
			if (k==0) break;
			curp = maxpower(k);
			times = k/pows[curp];
			att[curp] = times;
		}
		// make ans
		curnum = 0; // in the whole permu
		curset = 0; // forward
		len_incr = 0;
		backs_p = 0;
		if (att[maxp] > 1) len_incr++; // need to multiply (factor)
		// loop
		for (i=maxp; i>=0; i--){
			backcp_p = 0;
			if (att[i] == 1){
				for (j=0; j<len_incr; j++){ // len incr
					backcp[backcp_p++] = (++curnum);
				}
			} else if (att[i] > 1){
				for (j=0; j<att[i]; j++)
					backcp[backcp_p++] = (curnum+att[i]-j);
				curnum += att[i];
				for (j=0; j<(len_incr-1); j++){ // one already done by factors above
					backcp[backcp_p++] = (++curnum);
				}
			}
			for (j=backs_p; j<(backs_p+backcp_p); j++){
				backs[j] = backcp[backcp_p - 1 - (j-backs_p)]; // reversed
			}
			backs_p+=backcp_p;

			if (i==0) break;
			for (j=0; j<8; j++)
				fwds[(8*curset) + 7-j] = (++curnum);
			curset++;
			len_incr++;
		}
		// print
		n = 8*curset + backs_p;
		p(n);
		for (i=backs_p-1; i>=0; i--){
			printf("%d ", backs[i]); // reverse
		}
		for (i=0; i<(8*curset); i++){
			printf("%d ", fwds[i]);
		}
		printf("\n");
	}

	return 0;
}