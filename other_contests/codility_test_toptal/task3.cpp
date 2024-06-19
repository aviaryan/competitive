// you can use includes, for example:
// #include <algorithm>

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


int minAns;
int varr[100000];
int size;
int dg;

void binSearch(int l, int r){
	if (r < l) return;

	int mid = (l+r)/2, i;
	// try to reach
	// if reach, go left, else go right
	int cp = -1;
	for (i=0; i<size; i++){
		if (varr[i] == -1) continue; // no stone
		if (varr[i] <= mid) { // stone up
			if ((i-cp) > dg) {
				// fail
				binSearch(mid+1, r);
				return;
			} else {
				cp = i; // reach that stone
			}
		}
	}
	// cout << "loop" << l << r << mid << " " << size-cp << endl;
	if ((size-cp) > dg){ // fail
		binSearch(mid+1, r);
	} else {
		minAns = min(minAns, mid);
		binSearch(l, mid-1);
	}
}

int solution(vector<int> &A, int D) {
	minAns = 100001;
	// convert vector to array
	vector<int>::iterator vit;
	int ct = 0;
	for (vit = A.begin(); vit != A.end(); vit++){
		varr[ct++] = *vit;
	}
	size = A.size();
	dg = D;

    binSearch(0, size);

    if (minAns == 100001){
    	return -1;
    } else {
    	return minAns;
    }
}


int main(){
	int i;
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(5);

	cout << solution(v, 1) << endl;
	return 0;
}
