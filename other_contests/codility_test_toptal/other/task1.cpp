#include "bits/stdc++.h"
using namespace std;

struct tree {
  int x;
  tree * l;
  tree * r;
};

typedef struct tree tree;

int maxAns;

void solution_recurse(tree * T, set <int> s){
	if (s.find(T->x) == s.end())
    	s.insert(T->x);

	if (T->l != NULL){
		set <int> s1;
		s1.insert(s.begin(), s.end());
    	solution_recurse(T->l, s1);
    } else {
    	maxAns = max(maxAns, (int) s.size());
    }

    if (T->r != NULL){
    	set <int> s2;
		s2.insert(s.begin(), s.end());
    	solution_recurse(T->r, s2);
    } else {
    	maxAns = max(maxAns, (int) s.size());
    }
}

int solution(tree * T){
	maxAns = 0;
    if (T->l != NULL){
    	set <int> s;
    	s.insert(T->x);
    	solution_recurse(T->l, s);
    }
    if (T->r != NULL){
    	set <int> s;
    	s.insert(T->x);
    	solution_recurse(T->r, s);
    }
    return maxAns;
}


int main(){

	tree t1;
	t1.x = 3;
	t1.l = NULL; t1.r = NULL;

	tree t3;
	t3.x = 3;
	t3.l = NULL; t3.r = NULL;

	tree t2;
	t2.x = 5;
	t2.l = NULL; t2.r = &t3;

	tree t;
	t.x = 3;
	t.l = &t1;
	t.r = &t2;

	cout << solution(&t) << endl;
	return 0;
}

