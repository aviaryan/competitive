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

struct fp {
	int a,b,c,d;
};
typedef struct fp fp;
ll ans;
int a,b,c,d;

fp makefp(int a, int b, int c, int d){
	fp t;
	t.a = a; t.b = b; t.c = c; t.d = d;
	return t;
}

void flow(fp data, bool uid, int target){
	if (data.a > a || data.b > b || data.c > c || data.d > d)
		return;
	if (target == 0){
		//if (data.a == a && data.b == b && data.c == c && data.d == d)
			ans++;
		return;
	}
	if (uid == true){
		data.a += 1;
		flow(data, uid, target-1);
		data.a -= 1;
		data.c += 1;
		flow(data, !uid, target-1);
	} else {
		data.b += 1;
		flow(data, !uid, target-1);
		data.b -= 1;
		data.d += 1;
		flow(data, uid, target-1);
	}
}

int main(){
	int t, i;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	// rr rb br bb
	ans = 0;
	swap(c,d);
	fp temp;
	temp.a = a; temp.b = b; temp.c = c; temp.d = d;
	int tg = a+b+c+d;

	if (tg == 0){
		printf("2");
		return 0;
	}

	flow(makefp(1,0,0,0), 1, tg-1);
	flow(makefp(0,1,0,0), 1, tg-1);
	flow(makefp(0,0,1,0), 0, tg-1);
	flow(makefp(0,0,0,1), 0, tg-1);

	printf("%lld", ans);
	return 0;
}