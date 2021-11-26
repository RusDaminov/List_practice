#include <stdio.h>

typedef int Data;

typedef struct Node Node;
struct Node {
	Data data;
	Node * next;
};

int main() {

	Node * list = NULL;
	Node a = {3}, b = {17}, c = {21}, t = {10};
	list = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("%d ", a.data);
	printf("%d ", b.data);
	printf("%d ", c.data);
	printf("\n");

	return 0;
}
