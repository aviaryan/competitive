#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include <stdbool.h>


struct graphnode {
	struct graphnode * parent;
	int data;
	struct adjnode * next;
};

struct adjnode { // contains pointers to all childs of a node
	struct graphnode * gnode;
	struct adjnode * next;
};

struct graphnode * graphAddtoNode(struct graphnode * parent, int data){
	struct graphnode * node;
	node = (struct graphnode *) malloc( sizeof(struct graphnode) );
	node->data = data;
	node->parent = parent;
	node->next = NULL;
	// link it

	if (parent != NULL){
		struct adjnode * child = (struct adjnode *) malloc(sizeof(struct adjnode));
		child->gnode = node;
		child->next = parent->next;
		parent->next = child;
	}
	return node;
}

void graphMoveNodetoParent(struct graphnode * destparent, struct graphnode * srcchild){
	struct adjnode * next = (struct adjnode *) malloc(sizeof(struct adjnode));

	int s=0;
	if (srcchild->parent == NULL)
		s=1;

	next->next = destparent->next;
	next->gnode = srcchild;
	srcchild->parent = destparent;
	destparent->next = next;

	if (s==1)
		return;

	struct adjnode * temp = (srcchild->parent)->next, *prev = NULL;
	struct adjnode ** tempcpy = & ((srcchild->parent)->next); // double pointer is needed else tempcpy as a local var is modified
	// delete old
	while ( (temp->gnode)->data != srcchild->data ){
		prev = temp;
		temp = temp->next;
	}

	if (prev != NULL)
		prev->next = temp->next;
	else
		*tempcpy = temp->next;
}

int countAllChilds(struct graphnode * parent){
	int ans=0;
	struct adjnode * next = parent->next;
	while (next != NULL){
		ans += 1+countAllChilds(next->gnode);
		next = next->next;
	}
	return ans;
}

int isRoot(struct graphnode * anynode){
	return anynode->parent == NULL;
}

struct graphnode * findRoot(struct graphnode * anynode){
	while (anynode->parent != NULL){
		//printf("_%d", (anynode->parent)->data);
		anynode = anynode->parent;
	}
	return anynode;
}

// MAIN

int main(){
	int n,m,i,a,b;
	scanf("%d %d", &n, &m);
	if (n==1){
		printf("0\n");
		return 0;
	}

	long long int ans = 0;
	bool astroDone[n];
	for (i=0; i<n; i++)
		astroDone[i] = 0;
	struct graphnode * gnodes[n];

	for (i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if ( astroDone[a] + astroDone[b] == 0 ){
			gnodes[a] = graphAddtoNode(NULL, a);
			gnodes[b] = graphAddtoNode(gnodes[a] , b);
			astroDone[a] = 1, astroDone[b] = 1;
		}
		else if ( astroDone[a] == 1 && astroDone[b] == 0 ){
			gnodes[b] = graphAddtoNode(gnodes[a], b);
			astroDone[b] = 1;
		}
		else if ( astroDone[b] == 1 && astroDone[a] == 0 ){
			gnodes[a] = graphAddtoNode(gnodes[b], a);
			astroDone[a] = 1;
		}
		else {
			if ( findRoot(gnodes[a]) != findRoot(gnodes[b]) ){ // if both are not in same graph
				//printf("_%d", findRoot(gnodes[b])->data );
				graphMoveNodetoParent(gnodes[a], findRoot(gnodes[b]) );
			}
		}
	}

	// COUNT ALL PARENTS
	int nonlinked = 0, childs;
	for (i=0; i<n; i++){
		if (astroDone[i] == 0)
			nonlinked++;
		else if (isRoot(gnodes[i])){
			childs = countAllChilds(gnodes[i])+1;
			//printf("%d-%d", i, childs);
			ans += (childs) * (n-childs);
		}
	}

	ans += ((long long int) nonlinked * (n-1));
	printf("%lld\n", ans/2);
	return 0;
}