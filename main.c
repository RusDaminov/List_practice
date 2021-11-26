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

	printf("That's it\n");
	return 0;
}
