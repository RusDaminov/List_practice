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
int is_empty(Node * list);
int pop(Node ** pList);

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

int pop(Node ** pList){
	Node * p = *pList;
	Data res = p->data;
	*pList = p->next;
	free(p);
	return res;
}

int is_empty(Node * list){
	return list == NULL;
}

int main() {
	Data test[] = {21, 17, 3, 10};
	Node * list = NULL;
	size_t i = 0;

	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");
	while (i < sizeof(test)/sizeof(test[0])){
		push(&list, test[i]);
		print(list);
		i++;
	}
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");

	while(!is_empty(list)){
		Data d = pop(&list);
		printf("pop %d ", d);
		print(list);
	}
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");

	return 0;
}
