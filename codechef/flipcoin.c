#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

struct node {
	int data; struct node * next; };
typedef struct node node;

void insert(int d){
	node * temp = head;
	while (node->next != ){

	}
}

node * head;


int main(){
	int n, q, i, a, b, z, ans;
	scanf("%d %d", &n, &q);
	bool arr[n], s;
	memset(arr, 0, n);

	while (q--){
		scanf("%d %d %d", &z, &a, &b);
		if (z==0){
			if (arr[a] == 0) arr[a] = 1; else arr[a] = 0;
			if (b+1 != n)
				if (arr[b+1] == 0) arr[b+1] = 1; else arr[b+1] = 0;
			continue;
		}
		s = 0; ans = 0;
		for (i=0; i<=(a-1); i++)
			if (arr[i]) s = !s;
		for (i=a; i<=b; i++){
			if (arr[i]) s = !s;
			if (s) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}