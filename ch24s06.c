#include <stdio.h>
#include <stdarg.h>

void myprintf(const char *format, ...) {
    va_list ap;
    char c;

    va_start(ap, format);
    while (c = *format++) {
        if (c == '%') {
            c = *format++;
            int i;
            if (c == 'd') {
                i = va_arg(ap, int);
            } else if (c == 'f') {
                i = va_arg(ap, double);
            }

            unsigned int ui;
            if (i < 0) {
                putchar('-');
                ui = -i;
            } else {
                ui = i;
            }

            unsigned int mask = 1;
            while (mask*10 < ui) {
                mask *= 10;
            }
            
            do {
                putchar(48 + (int)ui/mask);
                ui %= mask;
                mask /= 10;
            } while (ui > 0);
        } else {
            putchar(c);
        }
    }
    va_end(ap);
}

int main(void) {
    myprintf("%d\n%f\n123\n", 1245, 3.997);
    return 0;
}
