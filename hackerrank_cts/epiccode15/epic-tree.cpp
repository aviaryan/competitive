#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/* 
need o1 query time
only possible if sum is stored at node
possible but lengthy
or logn ... sum stored in all nodes part by part
*/
struct node {
	vector<int> childs;
	int parent;
	ll ohead;
};

struct node arr[100001];
int nodehts[100001];
vector<int>::iterator pubit;

void calcHs(int ch, int nid){
	nodehts[nid] = ch;
	vector<int>::iterator vit;
	for (vit = arr[nid].childs.begin() ; vit != arr[nid].childs.end() ; vit++ ){
		calcHs(ch+1, *vit);
	}
}

void procPath(int a, int b, int t){
	int ah = nodehts[a];
	int bh = nodehts[b];
	int s;
	if (ah > bh) {
		swap(a, b); swap(ah, bh);
	}

	vector <int> bs; vector <int> as;
	while (bh != ah){ // same ht
		bs.push_back(b);
		b = arr[b].parent;
		bh--;
	}

	while (1){
		if (b == a){
			as.push_back(a); // a is at 1 too
			break;
		}
		bs.push_back(b);
		as.push_back(a);
		a = arr[a].parent;
		b = arr[b].parent;
	}

	// fill the values
	s = as.size();
	for (pubit = as.begin(); pubit != as.end(); pubit++){
		arr[ *pubit ].ohead += t;
	}
	for (pubit = bs.begin(); pubit != bs.end(); pubit++)
		arr[ *pubit ].ohead += t;
}

ll sumIn(int a, ll oh){
	ll k = arr[a].ohead + oh;
	ll ans = k;
	vector<int>::iterator vit;
	for (vit = arr[a].childs.begin(); vit != arr[a].childs.end() ; vit++ )
		ans += ( sumIn(*vit, k) );
	return ans;
}

int main(){
	int t, i, n, a, b, m, op;
	ll oh;
	ios_base::sync_with_stdio(0);
	cin >> n;

	arr[0].ohead = 0; // see in option 2
	arr[1].parent = 0;
	for (i=1; i<n; i++){
		cin >> a >> b;
		arr[a].childs.push_back(b);
		arr[b].parent = a;
		arr[a].ohead = 0; arr[b].ohead = 0;
	}

	calcHs(0, 1);

	cin >> m;
	while (m--){
		cin >> op;
		if (op == 1){
			cin >> a >> b >> t;
			procPath(a, b, t);
		} else {
			cin >> a;
			op = a; oh = 0;
			while (op != 1){
				op = arr[op].parent;
				oh += arr[op].ohead;
			}
			//cout << "oo" << oh;
			oh = sumIn(a, oh);
			cout << oh % 10009 << endl;
		}
	}


	return 0;
}