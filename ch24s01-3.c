#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        int a = malloc(10);//Memory leak
    }
}