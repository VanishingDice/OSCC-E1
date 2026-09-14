#include <stdlib.h>
#include "linkedlist.h"

static link head = NULL;
static link tail = NULL;

link make_node(unsigned char item) {
    link p = malloc(sizeof *p);
    p->item = item;
    p->next = NULL;
    return p;
}

void free_node(link p) {
    free(p);
}

link search(unsigned char key) {
    link p;
    for (p = head; p; p = p->next) {
        if (p->item == key) {
            return p;
        }
    }
    return NULL;
}

void insert(link p) {
    p->next = head;
    head = p;
}

void delete(link p) {
    link pre;
    if (p == head) {
        head = p->next;
        return;
    }
    for (pre = head; pre; pre = pre->next) {
        if (pre->next == p) {
            pre->next = p->next;
            return;
        }
    }
}

void traverse(void (*visit)(link)) {
    link p;
    for (p = head; p; p = p->next) {
        visit(p);
    }
}

void destroy(void) {
    link q, p = head;
    head = NULL;
    while (p) {
        q = p;
        p = p->next;
        free_node(q);
    }
}

void push(link p) {
    insert(p);
}

link pop(void) {
    if (head == NULL) {
        return NULL;
    } else {
        link p = head;
        head = head->next;
        return p;
    }
}

void order_insert(link p) {
    if (head == NULL) {
        head = p;
        return;
    } else {
        if (p->item < head->item) {
            p->next = head;
            head = p;
            return;
        }
        link q = head;
        // for (q = head; p->item < q->item; q = q->next) {}
        while (q->next != NULL) {
            if (p->item < q->next->item) {
                break;
            }
            q = q->next;
        }
        if (q->next != NULL) {
            p->next = q->next;
        }
        q->next = p;
    }
}

void enqueue(link p) {
    if (tail != NULL) {
        tail->next = p;
    }
    tail = p;
    if (head == NULL) {
        head = p;
    }
}

link dequeue(void) {
    if (head == NULL) {
        return NULL;
    } else {
        link p = head;
        head = head->next;
        return p;
    }
}

void reverse(void) {
    link p, next, prev;
    prev = NULL;
    p = head;
    while (p != NULL) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    head = prev;
}