#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char *strtok(char *str, const char *delim) {
    static char *index = NULL;
    static char *indexNext;
    if (str != NULL) {
        index = str;
        indexNext = index;
    } else {
        index = indexNext;
    }

    if (index == NULL && str == NULL) {
        return NULL;
    }

    int i = 0;
    while (indexNext[0] != '\0') {
        i = 0;
        while (delim[i] != '\0') {
            if (indexNext[0] == delim[i]) {
                if (indexNext == index) {
                    ++index;
                    break;
                }

                indexNext[0] = '\0';
                ++indexNext;
                return index;
            }
            ++i;
        } 
        ++indexNext;
    }

    if (index == indexNext) {
        return NULL;
    } else {
        return str;
    }
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
        *saveptr = NULL;
        return NULL;
    } else {
        return str;
    }
}

/*
NAME
    URLDecode - decode a url link to an array

SYNOPSIS
    #include <stdlib.h>
    #include <string.h>

    char *URLDecode(char *url, char *param[][2]);

DESCRIPTION
    The URLDecode() function use strtok_r to seperate the domain part
    and the parameters from the url string. A pointer to the domain name
    (characters before '?') will be returned. The key-value pairs is 
    separated by '&'. Key and value is separated by '=', keys will be 
    written to param[n][0], values will be written to param[n][1], 
    you should make sure there are enough space in param.
    e.g."http://www.baidu.com/s?wd=linux&cl=3"will be separated like:
    Domain:http://www.baidu.com/s
    key:wd  value:linux
    key:cl  value:3

RETURN VALUE
    The shrink_space() function return a pointer to the domain part.

CONFORMING TO 
    C99.

NOTES
    You should make sure the url is ended with '\0'

Ver 0.0.1
2026/9/12
*/
char *URLDecode(char *url, char *param[][2]) {
    char *index, *subindex, *indexNext;
    strtok_r(url, "?", &indexNext);
    int i = 0;
    while ((index = strtok_r(NULL, "&", &indexNext)) != NULL) {
        strtok_r(index, "=", &subindex);
        param[i][0] = index;
        param[i][1] = subindex;
        ++i;

    }
    return url;
    
}

int main0(void) {
	char str[] = "root:x.:0,root:,/root,/bin/bash:";
	char *token;

	token = strtok(str, ":,.");
	printf("%s\n", token);
	while ( (token = strtok(NULL, ":,.")) != NULL)
		printf("%s\n", token);
	
	return 0;
}

int main1(int argc, char *argv[]) {
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

int main(void) {
    char url1[100] = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
    char url2[100] = "http://www.baidu.com/s?wd=linux&cl=3";

    char *(*param)[2];
    param = malloc(200);
    if (param == NULL) {
        printf("out of memory\n");
        exit(1);
    }

    printf("Domain:%s\n", URLDecode(url1, param));
    for (int i = 0; param[i][0]!=NULL; ++i) {
        printf("key:%s \tvalue:%s\n", param[i][0], param[i][1]);
    }

    memset(param, 0, 200);

    printf("Domain:%s\n", URLDecode(url2, param));
    for (int i = 0; param[i][0]!=NULL; ++i) {
        printf("key:%s \tvalue:%s\n", param[i][0], param[i][1]);
    }

    free(param);
    return 0;
}
