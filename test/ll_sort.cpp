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

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode * createLL(int head){
	struct ListNode list;
	list.val = head;
	list.next = NULL;
	return &list;
}

void addToLL(struct ListNode *head, int value){
	struct ListNode * next = head->next;
	struct ListNode * temp;
	while (next != NULL){
		temp = next;
		next = head->next;
		head = temp;
	}
	// create new node
	struct ListNode * newNode = createLL(value);
	// add to head
	head->next = newNode;
	return;
}

void printLL(struct ListNode *head){
	struct ListNode * next = head;
	while (next != NULL){
		cout << next->val << ", ";
		next = next->next;
	}
	cout << endl;
	return;
}


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	// cin >> t;
	struct ListNode * l1 = createLL(1);
	// addToLL(l1, 4);
	// addToLL(l1, 5);
	// printLL(l1);

	return 0;
}
