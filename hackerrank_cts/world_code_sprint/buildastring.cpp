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

struct cell {
	int wt;
	struct cell * arr[26];
};
typedef struct cell cl;
char str[3*10000 + 1];
int n, a, b;
cl * heads[26];
int costs[3*10000 + 1];


void makeWeb(){
	int i, cur, it;
	int prev = str[0]-97;
	heads[prev] = (cl*) malloc(sizeof(cl));
	for (it=0; it<26; it++) heads[prev]->arr[it] = NULL;
	heads[prev]->wt = 0;
	cl * pptr;
	pptr = heads[prev];
	for (i=1; i<n; i++){
		cur = str[i]-97;
		//printf("%u\n", heads[prev]);
		if (heads[prev]->arr[cur] == NULL){
			//printf("create new %d", i);
			heads[prev]->arr[cur] = (cl*) malloc(sizeof(cl));
			for (it=0; it<26; it++) heads[prev]->arr[cur]->arr[it] = NULL;
			heads[prev]->arr[cur]->wt = i;
		}
		pptr->arr[cur] = heads[prev]->arr[cur];
		pptr = heads[prev]->arr[cur]; // prev flow
		prev = cur; // prev head
		if (heads[cur] == NULL){ // head missing
			heads[cur] = (cl*) malloc(sizeof(cl));
			for (it=0; it<26; it++) heads[cur]->arr[it] = NULL;
			heads[cur]->wt = i-1;
			//printf("new %d", i);
		}
	}
}

int solve(){
	// simple for now
	char c;
	int i, k, j;
	cl * tree;
	costs[n] = 0;

	for (i=n-1; i>=0; i--){
		k = str[i] - 97;
		j = i;
		tree = heads[str[j] - 97];
		j++;
		while (j < n){
			if (tree->arr[str[j] - 97] == NULL)
				break;
			if (tree->arr[str[j] - 97]->wt >= i)
				break;
			printf("flow: %d\n", tree->arr[str[j]-97]->wt);
			tree = tree->arr[str[j] - 97];
			j++;
		}
		costs[i] = min(b + costs[j], a + costs[i+1]);
		printf("cst: %d %c\n", costs[i], str[i]);
	}
	return costs[0];
}

int main(){
	int t, i, ans;
	scanf("%d", &t);

	while (t--){
		scanf("%d%d%d", &n, &a, &b);
		scanf("%s", str);
		for (i=0; i<26; i++) heads[i] = NULL;
		makeWeb();
		ans = solve();
		p(ans);
	}

	return 0;
}


/*
1
9 4 5
aabaacaba
*/