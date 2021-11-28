#include "list.h"

CNode* Search(CNode* head, int a) {
	CNode *current = head;
	while (current != 0) {
		if (current->Data == a)
			return current;
		current = current->Next;
	}
	return 0;
}
CNode* InsertAfter(CNode* node, int a){
	assert(node != 0);
	CNode* newNode = new CNode();
	newNode->Data = a;
	newNode->Next = node->Next;
	newNode->Prev = node;
	if(node->Next != 0){
		node->Next->Prev = newNode;
	}
	node->Next = newNode;
	return newNode;
}
void DelNode(CNode* node){
	node->Prev->Next = node->Next;
	node->Next->Prev = node->Prev;
	node->Data = 0;
	free(node);
}
CNode* Union(CNode* head1, CNode* head2){
	if(head1 == 0)
		return head2;
	if(head2 == 0)
		return head1;
	CNode* tail1 = head1;
	for(; tail1->Next != 0; tail1 = tail1->Next);
	tail1->Next = head2;
	return head1;
}