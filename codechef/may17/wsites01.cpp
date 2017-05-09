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


struct node {
	bool good, bad, root;
	char c;
	struct node * parent;
	struct node * childs;
};

// vars
struct node roots[26];
int ct;
char out[4 * 100000 + 1];

// end vars

struct node makeNode(char c, bool isBad, bool isRoot){
	struct node t;
	t.good = !isBad;
	t.bad = isBad;
	t.root = isRoot;
	t.c = c;
	t.childs = (struct node *) malloc(26 * sizeof(struct node));
	for (int i=0; i<26; i++){
		t.childs[i].good = false; t.childs[i].bad = false;
	}
	return t;
}

bool isNodeInit(struct node * nd){
	return !(nd->good == false && nd->bad == false);
}

void recurse(struct node * nd, int lct){ // only if +-
	if (ct < 0) // tragedy
		return;

	int i;
	struct node * nn;
	bool foundGood = false, foundBad = false, endHere = true;
	for (i=0; i<26; i++){
		nn = &(nd->childs[i]);
		if (isNodeInit(nn)){
			if (nn->good && nn->bad){
				endHere = false;
				recurse(nn, lct+1);
			}
			if (nn->good) foundGood = true;
			if (nn->bad) foundBad = true;
		}
	}
	// no bad ahead but goods, cant firewall bad, end here
	if (!foundBad){
		ct = -1 * MODULO;
		return;
	}

	char cstr[lct + 4];
	struct node * tmp;
	int tlct = lct;
	// good..bad and bad..good
	for (i=0; i<26; i++){
		nn = &(nd->childs[i]);
		if (isNodeInit(nn)){
			if (nn->good == false && nn->bad == true){
				// print string
				tmp = nn; tlct = lct;
				while (true){
					cstr[tlct--] = tmp->c;
					if (!tmp->root)
						tmp = tmp->parent;
					else
						break;
				}
				cstr[lct+1] = '\n';
				cstr[lct+2] = '\0';
				strcat(out, cstr);
				// printf("END %s\n", cstr);
				ct ++;
			}
		}
	}
}

void insert(char * str, int len, bool isBad){
	int i;
	// printf("hii\n");
	struct node * nd = &roots[str[0] - 97];
	struct node * prev;
	// printf("hii\n");

	for (i=0; i<len; i++){
		if (!isNodeInit(nd)){ // no init
			*nd = makeNode(str[i], isBad, (i==0));
			if (i > 0) nd->parent = prev; // set parent
		} else {
			// printf("what\n");
			if (isBad)
				nd->bad = true;
			else
				nd->good = true;
		}
		if (i == len-1) break;
		prev = nd;
		nd = &(nd->childs[str[i+1] - 97]);
	}
}

int main(){
	int t, i, n;
	s(n);
	char ch, temp;
	char str[2 * 100000 + 10], chs[5];
	out[0] = '\0';
	ct = 0;

	// init
	for (i=0; i<26; i++){
		roots[i].good = false; roots[i].bad = false;
	}

	for (i=0; i<n; i++){
		scanf("%s %s", chs, str); // capture \n
		ch = chs[0];
		// works on my computer
		// scanf("%c%c %s", &temp, &ch, str); // capture \n
		assert((ch == '+') || (ch == '-')); // INPUT MF
		// assert(str[0] != ' ');
		// printf("%s\n", str);
		insert(str, strlen(str), (ch == '-'));
	}

	for (i=0; i<26; i++){
		if (isNodeInit(&roots[i])){
			if (roots[i].good && roots[i].bad)
				recurse(&roots[i], 1);
			else if (roots[i].bad == true && roots[i].good == false){
				// printf("END %c\n", roots[i].c);
				char cstr[3];
				cstr[0] = roots[i].c; cstr[1] = '\n'; cstr[2] = '\0';
				strcat(out, cstr);
				ct ++;
			}
		}
		if (ct < 0) break;
	}

	if (ct < 0){
		printf("-1\n");
		return 0;
	}

	p(ct);
	printf("%s", out);

	return 0;
}