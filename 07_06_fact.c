#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x, n = 0;
    int result = 1;
    printf("x n? ");
    scanf("%d %d", &x, &n);
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    printf("%d\n", result);
    return 0;
}