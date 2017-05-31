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


int main(){
	int t, i, len, mc, eat;
	s(t);
	char str[101];

	while (t--){
		scanf("%s", str);
		len = strlen(str);
		mc = 0; eat = 0;
		for (i=0; i<len; i++){
			if (str[i] == 'm'){
				mc ++;
				if (i > 0 && str[i-1] == 's'){
					eat++;
				} else if (i+1 < len && str[i+1] == 's'){
					str[i+1] = 'o';
					eat++;
				}
			}
		}
		if (mc > (len - mc - eat)){
			printf("mongooses\n");
		} else if (mc == (len - mc - eat)){
			printf("tie\n");
		} else {
			printf("snakes\n");
		}
	}

	return 0;
}
