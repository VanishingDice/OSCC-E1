/*
NAME
    shrink_space - clear empty characters

SYNOPSIS
    #include <string.h>

    char *shrink_space(char *dest, const char *src, size_t n);

DESCRIPTION
    The shrink_space() function clears empty characters in the string
    pointed to by src, including '\t', '\n', and '\r'. For spaces, 
    it shrinks multi continuous spaces to one space.

RETURN VALUE
    The shrink_space() function return a pointer to the destination
    string dest.

CONFORMING TO 
    C99.

NOTES
    If '\0' occurs before n, the rest of the string will be filled
    with '\0'.

BUGS
    Remember to check n.

Ver 0.0.1
2026/9/11

*/


#include <stdio.h>

char *shrink_space(char *dest, const char *src, size_t n);

int main() {
    char str[] = "This Content hoho       is ok\n        ok?\n        file system\n uttered words   ok ok      ?\nend.";
    char dest[100];
    shrink_space(dest, str, 100);
    printf("%s\n", dest);
    return 0;
}

char *shrink_space(char *dest, const char *src, size_t n) {
    int srcIndex = 0;
    int destIndex = 0;
    char spaceFlag = 0;
    char currentChar;
    while (srcIndex < n) {
        currentChar = src[srcIndex];
        if (currentChar == '\0') {
            break;
        }
        if (currentChar == '\n' || currentChar == '\t' || currentChar == '\r') {
            ++srcIndex;
            continue;
        }
        if (currentChar == ' ' && spaceFlag == 1) {
            ++srcIndex;
            continue;
        }
        dest[destIndex] = currentChar;
        ++destIndex;
        ++srcIndex;
        if (currentChar == ' ') {
            spaceFlag = 1;
        } else {
            spaceFlag = 0;
        }
    }
    while (srcIndex < n) {
        dest[srcIndex++] = '\0';
    }
    return dest; 
}