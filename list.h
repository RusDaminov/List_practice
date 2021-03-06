#ifndef LIST_LIST_H
# define LIST_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;

struct CNode{
	int Data;
	struct CNode* Next;
	struct CNode* Prev;
//	CNode() : Data(0), Next(0), Prev(0){}
};

struct Node {
	Data data;
	struct Node * next;
	struct Node * prev;
};

void print(Node * list); // O(n)
void print_back(Node * list);
void print_dbg(Node * list);
int is_empty(Node * list);
Data pop_front(Node * List);
Data pop_back(Node * List);
Node * create();
void init(Node * list);
void destroy(Node * list);

void insert(Node * p, Node * t); // w/o malloc
void insert_before(Node * p, Node * t);
void ft_remove(Node * t);

void push(Node **pList, Data d); // w malloc
void push_before(Node **pList, Data d);
Data list_delete(Node * t);



//TechnoPark
//CNode* Search(CNode* head, int a);
//CNode* InsertAfter(CNode* node, int a);
//void DelNode(CNode* node);
//CNode* Union(CNode* head1, CNode* head2);

#endif //LIST_LIST_H
