#include "list.h"

void print(Node * list){
	Node * p = list->next;
	while(p != list) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void print_dbg(Node * list){
	Node * p = list->next;
//	printf("%d prev=%p %p next=%p", p->data, p->prev, p, p->next);
	while(p != list) {
		printf("%d prev=%p %p next=%p", p->data, p->prev, p, p->next);
		p = p->next;
		printf("\n");
	}
	printf("\n");
}
void print_back(Node * list){
	Node * p = list->prev;
	while(p != list) {
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\n");
}
void insert(Node * p, Node * t){
	Node * q = p->next;	// aka &b
	t->prev = p;	//1
	t->next = q;	//2
	p->next = t;	//3
	q->prev	= t;	//4

}
void insert_before(Node * q, Node * t){
	insert(q->prev, t);
}
void init(Node * list){
	list->next = list;
	list->prev = list;
}
int is_empty(Node * list){
	return list->prev == list->next && list->next == list;
}
void ft_remove(Node * t){
	Node * p = t->prev;	// 1
	Node * q = t->next;	// 2
	p->next = q;
	q->prev = p;
}
void test(){
	Node z,a, b, c, u, w;
	Node * list = &z;
	z.data = 0;
	a.data = 3;
	b.data = 17;
	c.data = 21;
	u.data = 10;
	w.data = 8;

	init(list);  //zhopa s ruchkami
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");

	insert(list, &c);
	print(list);  //  21

	insert(list, &b);
	print(list);  // 17 21

	insert(list, &a);
	print(list);  // 3 17 21

	print(list);  // 3 17 21
	print_dbg(list);
	print_back(list);  // 21 17 3

	insert(&a, &u);
	print(list);  // 3 10 17 21
	print_back(list);  // 21 17 10 3

	insert_before(&u, &w);
	print(list);  // 3 8 10 17 21
	print_back(list);  // 21 17 10 8 3

	ft_remove(&u);
	print(list);  // 3 8 17 21
	print_back(list);  // 21 17 8 3

	ft_remove(&w);
	print(list);  // 3 17 21
	print_back(list);  // 21 17 3
}
Node * push_front(Node * list, Data d){
	Node * p = malloc(sizeof(Node));
	p->data = d;
	insert(list, p);
	return p;
}
Node * push_back(Node * list, Data d){
	return push_front(list->prev, d);
}
Data list_delete(Node * t){
	ft_remove(t);
	Data d = t->data;
	free(t);
	return d;
}
Data pop_front(Node * list){
	return list_delete(list->next);
}
Data pop_back(Node * list){
	return list_delete(list->prev);
}
void clear(Node * list){
	while(!is_empty(list))
		pop_front(list);

}
void test_alloc(){
	Node z;
	Node * list = &z;

	Data test_data1 [] = {21, 17, 3};
	Data test_data2 [] = {10, 8};

	init(list);
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");

	Node * t;
	for (size_t i = 0; i < sizeof(test_data1)/sizeof(test_data1[0]); i++){
		t = push_front(list, test_data1[i]);
		print(list);
		printf("pushed: %d\n", t->data);
	}// 3 17 21
	for (size_t i = 0; i < sizeof(test_data2)/sizeof(test_data2[0]); i++){
		t = push_back(list, test_data2[i]);
		print(list);
		printf("pushed_back: %d\n", t->data);
	}// 3 17 21 10 8
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");

	t = list->next->next;
	Data res;

	res = list_delete(t);
	print(list); //3 21 10 8
	printf("deleted: %d\n", res);

	res = pop_front(list);
	print(list);	// 21 10 8
	printf("pop_front: %d\n", res); //3
	res = pop_back(list);
	print(list);	// 21 10
	printf("pop_back: %d\n", res); // 8

	clear(list);
	printf("Empty: %s\n", is_empty(list) ? "Yes" : "No");
}

int main(){
//	test();
	test_alloc();
	return 0;
}