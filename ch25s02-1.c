#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
		fprintf(stderr, "Incorrect var number");
		exit(EXIT_FAILURE);
	}
    char *source = argv[1];
    char *target = argv[2];
    FILE *sp;
    FILE *tp;
    if ((sp = fopen(source, "r")) == NULL) {
        perror("Open source file");
        exit(1);
    }
    if ((tp = fopen(target, "w")) == NULL) {
        perror("Open target file");
        exit(1);
    }
    int ch;
    while ((ch = fgetc(sp)) != EOF) {
        fputc(ch, tp);
    }
    fclose(sp);
    fclose(tp);
    printf("%s\n", "Task finished.");
    return 0;
}
