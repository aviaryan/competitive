#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%d", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// josephus problem

int main(){
	int t, i, n, j;
	//ios_base::sync_with_stdio(0);
	s(n);
	int pos[n+1];
	int fukpos[n+1];
	fill_n(pos, n+1, 0);
	int ptr = 1, x;

	for (i=1; i<=n; i++){
		scanf("%d", &j);

		x = ptr;
		j--;
		while (j > 0){
			x++;
			if (x>n) x=1;
			if (pos[x] != 0) continue;
			j--;
		}
		pos[x] = i;
		fukpos[i] = x;
		ptr = x;

		if (i==n) break;
		while (pos[ptr] != 0){
			ptr++;
			if (ptr>n) ptr=1;
		}
	}

	for (i=1; i<=n; i++)
		printf("%d\n", fukpos[i]);


	return 0;
}