#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct  Node
{
    Data data;
    struct Node *next;
    struct Node *prev;
}               Node;

void print(Node *list) {
    Node *p = list->next;
    while (p != list) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node z, a = {3}, b = {17}, c = {21};
    Node *list = &z;
    z.next = &a;    z.prev = &c;
    a.next = &b;    a.prev = &z;
    b.next = &c;    b.prev = &a;
    c.next = &z;    c.prev = &b;

    print(list); // 3 17 21
    return 0;
}