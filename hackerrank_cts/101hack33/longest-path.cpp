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

struct node {
	vector <int> childs;
	int hs;
	int shs;
	bool visited;
};

struct node arr[100000 + 1];
bool type[100000+1];

int solve(int node){
	arr[node].visited = true;
	if (type[node] == false)
		return 0;
	vector <int>::iterator vit;
	vector <int> anss;
	for (vit = arr[node].childs.begin(); vit != arr[node].childs.end(); vit++){
		//printf("hi");
		anss.push_back( solve(*vit) );
	}
	sort(anss.begin(), anss.end());
	if (anss.size() > 1){
		vit = anss.end();
		arr[node].hs = *(--vit);
		arr[node].shs = *(--vit);
	} else if (anss.size() > 0){
		vit = anss.end();
		arr[node].hs = *(--vit);
	}
	//printf("%d %d\n", node, arr[node].hs + 1);
	return arr[node].hs + 1;
}


int main(){
	int t, i, n;
	s(n);
	for (i=1; i<=n; i++){
		s(t);
		type[i] = t;
	}

	arr[1].visited = false;
	arr[1].hs = 0; arr[1].shs = 0;
	for (i=2; i<=n; i++){
		s(t);
		arr[t].childs.push_back(i);
		arr[i].visited = false;
		arr[i].hs = 0; arr[i].shs = 0;
	}

	// solve
	for (i=1; i<=n; i++){
		if (arr[i].visited == false)
			solve(i);
	}

	// ans
	int ans = 0;
	for (i=1; i<=n; i++){
		if (arr[i].hs > 0){
			ans = max(ans, arr[i].hs + arr[i].shs + 1);
		}
	}

	p(ans);

	return 0;
}