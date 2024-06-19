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

struct tree {
  int x;
  tree * l;
  tree * r;
};

typedef struct tree tree;

int maxZig;

void solution2(tree * T, bool d, int count){
	if (T->l != NULL) {
		solution2(T->l, false, count + (d==true ? 1 : 0));
	} else {
		maxZig = max(maxZig, count);
	}
	if (T->r != NULL) {
		solution2(T->r, true, count + (d==false ? 1 : 0));
	} else {
		maxZig = max(maxZig, count);
	}
}

int solution(tree * T) {
	maxZig = 0; // init global var
	if (T->l != NULL) {
		solution2(T->l, false, 0);
	}
	if (T->r != NULL) {
		solution2(T->r, true, 0);
	}
	return maxZig;
}


int main(){
	int i;

	tree t;
	t.x = 3;
	t.l = NULL;
	t.r = NULL;

	cout << solution(&t) << endl;
	return 0;
}
