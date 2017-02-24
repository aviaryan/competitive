#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define min(a,b) ((a)>(b)) ? (b) : (a)
#define max(a,b) ((a)>(b)) ? (a) : (b)


typedef unsigned long long ull;
typedef long long ll;

struct node {
	int left; int right; int max; int sum;
};

struct node T[4*50000];
int arr[50000+1];
int ct, x, y;
struct node ans, ans2;

struct node mix(struct node left, struct node right){
	struct node result;
	result.left = max(left.left, left.sum + right.left);
	result.sum = left.sum + right.sum;
	result.right = max(right.right, right.sum + left.right);
	result.max = max( max(left.max, right.max) , left.right + right.left );
	return result;
}

void buildT(int p, int l, int r){
	if (l == r){
		T[p].left = arr[l-1];
		T[p].right = arr[l-1];
		T[p].max = arr[l-1];
		T[p].sum = arr[l-1];
	} else {
		int mid = (l+r)/2;
		buildT(p*2, l, mid);
		buildT(p*2+1, mid+1, r);
		T[p] = mix(T[p*2], T[p*2+1]);
	}
}

void query(int p, int l, int r){
	if (x <= l && r <= y){
		if (ct){
			ans2 = mix(ans, T[p]);
			ans = ans2;
		} else
			ans = T[p];
		ct++;
	} else if (l <= y && r >= x){
		query(p*2, l, (l+r)/2);
		query(p*2+1, (l+r)/2 + 1, r);
	}
}

int main(){
	int i, n, q;
	scanf("%d", &n);

	for (i=0; i<n; i++) scanf("%d", arr+i);
	buildT(1, 1, n);

	scanf("%d", &q);
	while (q--){
		scanf("%d %d", &x, &y);
		ct = 0;
		query(1, 1, n);
		printf("%d\n", ans.max);
	}

	return 0;
}