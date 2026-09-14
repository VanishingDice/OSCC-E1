#include <stdio.h>
#include <unistd.h>
#include <string.h>

int findinclude(FILE *);
char *includepath[] = {
    {"/usr/include/\0"},
    {"/usr/lib/gcc/x86_64-linux-gnu/13/include/\0"},
    {"/usr/local/include/\0"},
    {"/usr/include/x86_64-linux-gnu/\0"}
};

int printpath(const char *name, int mode) { 
    FILE *file;
    char path[100];
    if (mode == 1) {
        getcwd(path, 100);
        path[strlen(path)] = '/';
        path[strlen(path)] = '\0';
        strncat(path, name, 99-strlen(path));
        if ((file = fopen(path, "r")) != NULL) {
            printf("%s\n", path);
            findinclude(file);
            fclose(file);
            return 0;
        } else {
            printf("%s: cannot find in user dir, finding in default fir...\n", path);
        }
    }

    for (int i = 0; i < 4; ++i) {
        strncpy(path, includepath[i], strlen(includepath[i])+1);
        strncat(path, name, 99-strlen(path));
        if ((file = fopen(path, "r")) != NULL) {
            printf("%s\n", path);
            findinclude(file);
            fclose(file);
            return 0;
        }
    }
    
    printf("%s: cannot find\n", path);
    return -1;
}

int findinclude(FILE *file) {
    fseek(file, 0, SEEK_SET);
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (strncmp(line, "#include <", 10) == 0) {
            *(strrchr(line, '>')) = '\0';
            printpath(line+10, 0);
        } else if (strncmp(line, "#include \"", 10) == 0) {
            *(strrchr(line, '\"')) = '\0';
            printpath(line+10, 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
		fprintf(stderr, "Incorrect var number");
		return 1;
    }
    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        perror("Open file");
        return 1;
    }
    findinclude(file);
    fclose(file);
    return 0;

}