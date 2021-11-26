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
	p->data = d;
	p->next = *pList;
	*pList = p;
}

int main() {
	Data test[] = {21, 17, 3, 10};
	Node * list = NULL;
	size_t i = 0;

	while (i < sizeof(test)/sizeof(test[0])){
		push(&list, test[i]);
		print(list);
		i++;
	}
//	Node a = {3};
//	Node b = {17};
//	Node c = {21};
//	Node t = {10};
//
//	list = &a;
//	a.next = &b;
//	b.next = &c;
//	c.next = NULL;
//
//	print(list);
//	push(&list, 10);
//
//	print(list);

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
