#ifndef LIST_LIST_H
# define LIST_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;

struct Node {
	Data data;
	struct Node * next;
	struct Node * prev;
};

void print(Node * list); // O(n)
int is_empty(Node * list);
Data pop(Node ** pList);
Node * create();
void init(Node * list);
void destroy(Node * list);

void insert(Node * p, Node * t); // w/o malloc
void insert_before(Node * p, Node * t);
Node * ft_remove(Node * t);

void push(Node **pList, Data d); // w malloc
void push_before(Node **pList, Data d);
Data delete(Node * t);

#endif //LIST_LIST_H
