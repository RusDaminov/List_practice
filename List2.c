#include "list.h"

//typedef struct Node {
//	struct Node * next;
//	struct Node * prev;
//	Data data;
//} Node;
void print(Node * list)
{
	Node * p = list->next;
	while(p != list) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void print_dbg(Node * list)
{
	Node * p = list->next;
//	printf("%d prev=%p %p next=%p", p->data, p->prev, p, p->next);
	while(p != list) {
		printf("%d prev=%p %p next=%p", p->data, p->prev, p, p->next);
		p = p->next;
		printf("\n");
	}
	printf("\n");
}

void print_back(Node * list)
{
	Node * p = list->prev;
	while(p != list) {
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\n");
}

int main(){

	Node z,a = {3}, b = {17}, c = {21};
	Node * list = &z;
	z.next = &a;
	z.prev = &c;
	a.next = &b;
	c.prev = &b;
	b.next = &c;
	b.prev = &a;
	c.next = &z;
	a.prev = &z;

	print(list);  // 3 17 21
	print_back(list);  // 21 17 3
	print_dbg(list);
	return 0;
}