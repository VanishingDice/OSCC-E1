#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

FILE *log_order;
int year, month, date, hour, minute, second;
unsigned long long order;
int count = 0;

void print_to_log(link p) {
    ++count;
    order = p->item;
    date = order%40;
    order /= 40;
    month = order%13;
    order /= 13;
    year = order%100 + 2000;
    order /= 100;
    second = order%60;
    order /= 60;
    minute = order%60;
    order /= 60;
    hour = order;
    fprintf(log_order, "%d %d-%d-%d %d:%d:%d\n", count, year, month, date, hour, minute, second);
}

int main() {
    FILE *log;
    if ((log = fopen("log.txt", "r")) == NULL) {
        perror("Open log file");
        return -1;
    }

    char line[100];
    
    link p;
    while (fgets(line, 100, log) != NULL) {
        sscanf(line, "%*d %d-%d-%d %d:%d:%d",&year,&month,&date,&hour,&minute,&second);
        order = (((((unsigned long long)hour*60+minute)*60+second)*100+(year%100))*13+month)*40+date;
        p = make_node(order);
        order_insert(p);
    }
    fclose(log);

    if ((log_order = fopen("log-order.txt", "w")) == NULL) {
        perror("Open log file");
        return -1;
    }

    traverse(print_to_log);

    destroy();
    return 0;
}
