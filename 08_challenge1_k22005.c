#include <stdio.h>
int main(int argc, const char * argv[]) {
    int input = 0;
    int n = 2;
    printf("input? ");
    scanf("%d", &input);
    while (input != 1) {
        while (input % n == 0) {
            input /= n;
            printf("%d", n);
            if (input != 1) {
                printf(", ");
            }
        }
        n++;
    }
    putchar('\n');
    return 0;
}