#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct stree {
    int degree;
    struct stree *cons[SIZE];
};

typedef struct stree tree;

int main(){
	int t;
	scanf("%d", &t);
	return 0;
}