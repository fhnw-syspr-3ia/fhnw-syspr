#include <stdio.h>

int main(void) {
    int c;
    do {
        printf("enter a digit: ");
        c = getchar();
    } while (c < '0' || '9' < c);
    return 0;
}
