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

int drop;

void addToString(string * s, int i, char dir){
	char buff[16];
	snprintf(buff, sizeof(buff), "%d %c\n", drop + (i+1), dir);
	(*s).append(buff);
}

int main(){
	int t, i, n, k, j;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];
	for (i=0; i<n; i++){
		cin >> arr[i];
	}
	cin >> k; 
	int narr[k];
	for (i=0; i<k; i++){
		cin >> narr[i];
	}
	// solve
	string out = "";
	int istart = 0, sum, mx, mx_i;
	drop = 0;
	bool b1, b2;
	for (j=0; j<k; j++){
		// find div
		sum = 0;
		for (i=istart; i<n; i++){
			sum += arr[i];
			if (sum >= narr[j])
				break;
		}
		// failed
		if (sum != narr[j])  
			break;
		// find order
		// find max
		mx = 0; mx_i = -1;
		for (t=istart; t<=i; t++){
			if (arr[t] > mx){
				b1 = (t-1 >= istart) ? (arr[t] > arr[t-1]) : false;
				b2 = (t+1 <= i) ? (arr[t] > arr[t+1]) : false;
				if (b1 || b2){
					mx_i = t;
					mx = arr[t];
				}
			}
		}
		// fail cases
		if (mx_i == -1){
			if (i > istart)  // 2 or more items
				break;
		} else {
			// find eats
			b1 = (mx_i-1 >= istart) ? (arr[mx_i] > arr[mx_i-1]) : false;
			if (b1){
				addToString(&out, mx_i, 'L');
				for (t=mx_i-1+1+1; t<=i; t++) 
					addToString(&out, mx_i-1, 'R');
				for (t=mx_i-1; t>istart; t--)
					addToString(&out, t, 'L');
			} else {
				addToString(&out, mx_i, 'R');
				for (t=mx_i+1+1; t<=i; t++)
					addToString(&out, mx_i, 'R');
				for (t=mx_i; t>istart; t--)
					addToString(&out, t, 'L');
			}
		}
		// preps
		drop -= (i-istart);
		istart = i+1;
	}
	// print answer
	if (j != k || istart != n)
		cout << "NO" << endl;
	else
		cout << "YES\n" << out << endl;

	return 0;
}