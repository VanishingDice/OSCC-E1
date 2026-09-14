#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

void print_item(link p) {
    printf("%lld\n", p->item);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Incorrect var number");
		return -1;
	}

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	link start = make_node(1);
	insert(start);
	link p = start;
	for(int i = 2; i <= n; ++i) {
		p = make_node(i);
		insert(p);
	}
	reverse();
	p->next = start;
	start->prev = p;

	link current = start;
	link next = current->next;
	while(1) {
		for (int i = 1; i < m; ++i) {
			current = current->next;
		}
		next = current->next;
		printf("%lld died.\n", current->item);
		delete(current);
		current = next;
		if (current == current->next) {
			printf("%lld survived!\n", current->item);
			break;
		}
	}
	
	return 0;
}