#include <stdio.h>

int main(void) {
    int a[2];
    a[0] = 123;
    a[1] = 456;
    printf("%d\n", 1[a]);
    int *pa = a;
    pa++;
    printf("negative index:%d\n", pa[-1]);
    printf("%u\n", pa);//print the address stored in pa
}