#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;

struct Node {
	Data data;
	Node * next;
};

void print(Node * list);
void push(Node **pList, Data d);

void print(Node * list)
{
	Node * p;
	p = list;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void push(Node **pList, Data d)
{
	Node * p = malloc(sizeof(Node));
	p->data = 10;
	p->next = *pList;
	*pList = p;
}

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

	print(list);
	push(&list, 10);

	print(list);

//	Node * p;
//	p = list;
//	while(p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("%d ", p->data);
//	p = p->next;
//	printf("%d ", p->data);
	return 0;
}
