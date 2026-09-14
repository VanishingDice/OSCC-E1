#include <stdio.h>
#include "linkedlist.h"

void print_item(link p) {
    printf("%d\n", p->item);
}

void sort_test(void) {
	link p = make_node(10);
	order_insert(p);
	p = make_node(5);
	order_insert(p);
	p = make_node(20);
	order_insert(p);
	p = make_node(21);
	order_insert(p);
	p = make_node(6);
	order_insert(p);
	p = make_node(5);
	order_insert(p);
}

void test(void) {
 	link p = make_node(10);
	insert(p);
	p = make_node(5);
	insert(p);
	p = make_node(90);
	insert(p);
	p = search(5);
	delete(p);
	free_node(p);
	traverse(print_item);
	destroy();

	p = make_node(100);
	push(p);
	p = make_node(200);
	push(p);
	p = make_node(250);
	push(p);
	while (p = pop()) {
		print_item(p);
		free_node(p);
	}

}

int main(void) {
   
	sort_test();

	return 0;
}