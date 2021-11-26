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

	print(list);
	printf("\n");

	return 0;
}