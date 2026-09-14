#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
struct node {
    long long item;
    link next;
    link prev;
};

link make_node(long long item);
void free_node(link p);
link search(long long key);
void insert(link p);
void delete(link p);
void traverse(void (*visit)(link));
void destroy(void);
void push(link p);
link pop(void);
void order_insert(link p);
void enqueue(link p);
link dequeue(void);
void reverse(void);

#endif