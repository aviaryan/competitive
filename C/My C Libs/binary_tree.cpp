#include "bits/stdc++.h"
using namespace std;

typedef pair <int, int> pii;

class BinTree {
	private:
		int head;
		map <int, int> locs;
		vector <pii> tree;

	public:
		BinTree(int data);
		void insertLeft(int, int);
		void insertRight(int, int);
		pii childOf(int parent);
		int height();
	private:
		void insertAt(int parent, int data, int where);
		int findNode(int data);
		pii initNode();
};

int BinTree::findNode(int data){
	return locs.find(data)->second;
}

pii BinTree::initNode(){
	pii p;
	p.first = -1, p.second = -1;
	return p;
}

BinTree::BinTree(int data){
	pii x = initNode();
	head = data;
	locs[data] = tree.size();
	tree.push_back(x);
	return;
}

void BinTree::insertAt(int parent, int data, int where){
	pii x = initNode();
	int pos = findNode(parent);
	if (where == 1)
		tree[pos].second = data;
	else
		tree[pos].first = data;
	locs[data] = tree.size();
	tree.push_back(x);
}

void BinTree::insertLeft(int p, int d){ insertAt(p, d, 0); }
void BinTree::insertRight(int p, int d){ insertAt(p, d, 1); }

pii BinTree::childOf(int parent){
	int z = findNode(parent);
	return tree[z];
}

// int BinTree::height_re(int d, int h){
// 	int z = findNode(d);
// 	if ( tree[z].first == -1 )
		
// }

// int BinTree::height(){
	

// }


int main(){
	BinTree mytree(2);
	// int x; bintree x;
	mytree.insertLeft(2,4);
	mytree.insertRight(2,7);

	pii p = mytree.childOf(2);

	cout << p.second;

	return 0;
}