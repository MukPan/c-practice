#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    while (n >= 0) {
        printf("%d\n", n);
        n -= 1;
    }
    return 0;
}