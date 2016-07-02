/* root is 1 the smallest number
   struct connects from small to big
   if exists a even node break it there only
   as break of even gives 2 even only so no problem
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100

struct stree {
    int degree;
    struct stree *cons[SIZE];
};

typedef struct stree tree;

// prototypes
int countchild(tree);
int evensubtrees(tree *ptr, int);


int main() {

    int n,m,a,b,i,ans;
    scanf("%d %d", &n, &m);

    tree node[n];

    // init to zero
    for (i=0; i<n; i++)
        node[i].degree = 0;

    // get data in
    for (i=0; i<m; i++){
        scanf("%d %d", &a, &b); // input style a>b
        node[b-1].cons[ node[b-1].degree ] = &node[a-1];
        node[b-1].degree ++;
    }

    ans = evensubtrees( &node[0] , n);
    printf("%d", ans);

    return 0;
}

int countchild(tree thenode){
    int z,i;
    z = thenode.degree;
    for (i=0; i<thenode.degree; i++){
        if ( (thenode.cons[i])->degree > 0 ) // if a subtree has some nodes
            z += countchild( *(thenode.cons[i]) );
    }
    return z;
}

int evensubtrees(tree *thenode, int n){
    int cc,i,ans=0;

    for (i=1; i<n; i++){
        cc = countchild( thenode[i] ) + 1;
        if (cc%2 == 0){ // even node found - break it
            ans++;
        }
    }

    return ans;
}