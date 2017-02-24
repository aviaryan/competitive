#include <stdio.h>
#include <malloc.h>

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

// MOVES NODE ACTUALLY
void graphMoveNodetoParent(struct graphnode * destparent, struct graphnode * srcchild){
	struct adjnode * next = (struct adjnode *) malloc(sizeof(struct adjnode));

	int s=0; // if srcchild is parent- just move it
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

void graphlistChilds(struct graphnode * parent){
	struct adjnode * next = parent->next;
	while (next != NULL){
		printf("%d\n", next->gnode->data);
		next = next->next;
	}
}

void graphHeight_intmd(struct graphnode * parent, int n, int *maxh){
	struct adjnode * next = parent->next;
	if (n>(*maxh))
		*maxh = n;
	while (next != NULL){
		graphHeight_intmd(next->gnode, n+1, maxh);
		next = next->next;
	}
}
int graphHeight(struct graphnode * parent){ // 0 for single parent
	int maxh=0;
	graphHeight_intmd(parent, 0, &maxh);
	return maxh;
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

struct adjnode * findChildinParent(struct graphnode * parent, struct graphnode * node){
	struct adjnode * next = parent->next;
	while (next->gnode != node)
		next = next->next;
	return next;
}

struct graphnode * findRoot(struct graphnode * anynode){
	while (anynode->parent != NULL)
		anynode = anynode->parent;
	return anynode;
}

int isRoot(struct graphnode * anynode){
	return anynode->parent == NULL;
}

void findNodeByData_bg(struct graphnode * parent, int data, struct graphnode ** found){
	struct adjnode * temp;
	temp = parent->next;
	while ( 1 ){
		if (temp == NULL)
			break;
		if (*found != NULL)
			break;
		if  ( (temp->gnode)->data == data ){
			*found = temp->gnode;
			break;
		}
		findNodeByData_bg(temp->gnode, data, found);
		temp = temp->next;
	}
}
struct graphnode * findNodeByData(struct graphnode * parent, int data){
	struct graphnode * found;
	if (parent->data == data)
		return parent;
	else
		findNodeByData_bg(parent, data, &found);
	return found;
}

void deleteNode(struct graphnode * node){
	struct graphnode * parent = node->parent;
	struct adjnode * next = parent->next, * prev = NULL;
	while (next->gnode != node)
		prev = next, next = next->next;

	if (next == NULL)
		return;
	if (prev == NULL)
		parent->next = next->next;
	else
		prev->next = next->next;
	free(next);
}

main(){
	//struct graph * mygraph = createGraph(5);
	struct graphnode * root = graphAddtoNode(NULL, 3);
	struct graphnode * child1 = graphAddtoNode(root, 4);
	struct graphnode * child2 = graphAddtoNode(root, 5);

	struct graphnode * child11 = graphAddtoNode(child1, 6);
	struct graphnode * child12 = graphAddtoNode(child1, 7);
	graphlistChilds(root);
	graphlistChilds(child1);

	printf("height of graph %d\n", graphHeight(root));
	printf("root ka childs %d\n", countAllChilds(root));

	deleteNode(child12);
	printf("root ka childs %d\n", countAllChilds(root));

	printf("root from anywhere %d\n", findRoot(child1)->data);
	printf("root ka childs %d\n", countAllChilds(root));

	// printf("child1 ka childs\n");
	// graphlistChilds(child1);
	graphMoveNodetoParent(root, child11);
	printf("root ka child list\n");
	graphlistChilds(root);
	printf("child1 ka childs\n");
	struct graphnode * child13 = graphAddtoNode(child1, 11);
	graphlistChilds(child1);

	printf("find childs %u, %d\n", findNodeByData(root, 11), findNodeByData(root, 11)->data);
}