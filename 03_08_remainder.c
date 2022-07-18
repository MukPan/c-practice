#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a, b;
    printf("a b? ");
    scanf("%d %d", &a, &b);
    printf("%d\n", a%b);
    return 0;
}