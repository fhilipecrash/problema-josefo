#include <stdio.h>
#include <stdarg.h>

void many_args(int count, ...) {
    va_list list;
    int j = 0;

    va_start(list, count);
    for (j=0; j<count; j++) {
        printf("%d", va_arg(list, int));
    }

    va_end(list);
}

void main() {
    many_args(6, 1, 2, 3, 4, 5, 6);
}