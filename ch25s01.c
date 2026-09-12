#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char *strtok(char *str, const char *delim) {
    static char *index = NULL;
    static char *(*saveptr);
    if (str != NULL) {
        index = str;
        (*saveptr) = index;
    } else {
        index = (*saveptr);
    }

    if (index == NULL && str == NULL) {
        return NULL;
    }

    int i = 0;
    while ((*saveptr)[0] != '\0') {
        i = 0;
        while (delim[i] != '\0') {
            if ((*saveptr)[0] == delim[i]) {
                if ((*saveptr) == index) {
                    ++index;
                    break;
                }

                (*saveptr)[0] = '\0';
                ++(*saveptr);
                return index;
            }
            ++i;
        } 
        ++(*saveptr);
    }

    return NULL;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
    if (str == NULL) {
        str = *saveptr;
    }

    *saveptr = str;
    int i = 0;
    while ((*saveptr)[0] != '\0') {
        i = 0;
        while (delim[i] != '\0') {
            if ((*saveptr)[0] == delim[i]) {
                if ((*saveptr) == str) {
                    ++str;
                    break;
                }

                (*saveptr)[0] = '\0';
                ++(*saveptr);
                return str;
            }
            ++i;
        } 
        ++(*saveptr);
    }

    if (str == *saveptr) {
        return NULL;
    } else {
        return str;
    }
}

char *URLDecode(char *url, char *param[][2]) {
    // char *addr = strtok(url, '?');
    int i = 0;
    do {
        param[i][0] = strtok(NULL, '&');
        ++i;
    } while (param[i-1][0] != NULL);
    
}

// int main(void)
// {
// 	char str[] = "root:x.:0,root:,/root,/bin/bash:";
// 	char *token;

// 	token = strtok(str, ":,.");
// 	printf("%s\n", token);
// 	while ( (token = strtok(NULL, ":,.")) != NULL)
// 		printf("%s\n", token);
	
// 	return 0;
// }

int main(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;
	int j;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s string delim subdelim\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, argv[2], &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = strtok_r(str2, argv[3], &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(EXIT_SUCCESS);
}