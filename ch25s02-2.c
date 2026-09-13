#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
		fprintf(stderr, "Incorrect var number");
		return 1;
	}
    char *source = argv[1];
    char *target = argv[2];
    FILE *sp;
    FILE *tp;
    if ((sp = fopen(source, "r")) == NULL) {
        perror("Open source file");
        return 1; 
    }
    if ((tp = fopen(target, "w")) == NULL) {
        perror("Open target file");
        return 1;
    }
    char ch[100];
    while (fgets(ch, 100, sp) != NULL) {
        fputs(ch, tp);
    }
    fclose(sp);
    fclose(tp);
    printf("%s\n", "Task finished.");
    return 0;
}

