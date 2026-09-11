#include <stdio.h>
// #include <cstring>

char* strcpy(char*, const char*);

int main() {
    char str[11];
    printf("%s\n", strcpy(str, "Hello World"));
    char str2[] = "Hello World";
    printf("%s\n", str2);

}

char* strcpy(char* dest, const char* src) {
    for(int i = 0; src[i-1] != '\0' || i == 0; ++i)
        dest[i] = src[i];
    return dest;
}