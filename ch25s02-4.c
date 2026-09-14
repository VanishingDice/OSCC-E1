#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    FILE *ini;
    // if ((ini = fopen("ch25s02-4-test.ini", "a")) == NULL) {
    //     perror("Open ini file a");
    //     return 1;
    // }
    // fputc('\n', ini);
    // fclose(ini);
    if ((ini = fopen("ch25s02-4-test.ini", "r")) == NULL) {
        perror("Open ini file r");
        return 1;
    }
    FILE *xml;
    if ((xml = fopen("ch25s02-4-test.xml", "w")) == NULL) {
        perror("Open xml file");
        return 1;
    }

    char line[100];
    int end = 0;
    int count = 0;
    char section[100];
    char key[100];
    char value[100];
    while (fgets(line, 100, ini) != NULL) {
        ++count;
        end = 0;
        while (line[end] != '\0') {
            ++end;
        }
        // if (line[end - 1] != '\n') {
        //     fprintf(stderr, "Error: line %d too long", count);
        //     fclose(ini);
        //     fclose(xml);
        //     return 1;
        // }

        if (line[0] == ';') {
            line[end - 1] = '\0';
            fprintf(xml, "<!-- %s -->\n", line+1);
        } else if (line[0] == '[') {
            //cut may happen
            sscanf(line, "[%99[^]]", (char *)&section);
            fprintf(xml, "<%s>\n", section);
        } else if (line[0] == ' ' || line[0] == '\n' 
            || line[0] == '\0' || line[0] == '\t') {
            if (section[0] != '\0') {
                fprintf(xml, "</%s>\n\n", section);
                section[0] = '\0';
            } else {
                fprintf(xml, "\n");
            }
        } else {
            //remove blank char(' ' and '\t')
            int i=0;
            int j=0;
            while (line[i] != '\n') {
                if (line[i] == ' ' || line[i] == '\t') {
                    ++i;
                    continue;
                }
                if (i != j) {
                    line[j] = line[i];
                }
                ++i;
                ++j;
            }
            line[j] = '\0';

            sscanf(line, "%99[^=]=%99[^\n]", (char *)&key, (char *)&value);
            fprintf(xml, "\t<%s>%s</%s>\n", key, value, key);
        }


    }
    fclose(ini);
    fclose(xml);
    return 0;
}