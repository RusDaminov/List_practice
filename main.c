#include <stdio.h>

typedef int Data;

typedef struct Node Node;
struct Node {
	Data data;
	Node * next;
};

int main() {

	Node * list = NULL;
	Node a = {3};
	Node b = {17};
	Node c = {21};
	Node t = {10};

	list = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	Node * p;
	p = list;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
//	printf("%d ", p->data);
//	p = p->next;
//	printf("%d ", p->data);
	printf("\n");

	return 0;
}
