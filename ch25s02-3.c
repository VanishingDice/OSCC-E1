#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    FILE *log;
    if ((log = fopen("ch25s02-3-test.txt", "a+")) == NULL) {
        perror("Open log file");
        return 1;
    }
    char lastlog[100];
    while (fgets(lastlog, 100, log) != NULL) {}
    printf("lastlog:%s\n", lastlog);
    int count;
    if (sscanf(lastlog, "%d", &count) == 0) {
        count = 1;
    }

    time_t second;
    struct tm *timestruct;
    char timestr[50];
    fseek(log, 0, SEEK_SET);
    while (1) {
        ++count;
        second = time(NULL);
        timestruct = localtime(&second);
        sprintf(timestr, "%d %d-%d-%d %.2d:%.2d:%.2d\n", 
            count,
            timestruct->tm_year + 1900, 
            timestruct->tm_mon + 1,
            timestruct->tm_mday,
            timestruct->tm_hour,
            timestruct->tm_min,
            timestruct->tm_sec);
        
        printf("%s", timestr);
        // fprintf(log, "%s", timestr);
        fputs(timestr, log);
        fflush(log);
        sleep(1);
    }

}