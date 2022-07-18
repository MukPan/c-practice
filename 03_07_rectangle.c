#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a, b;
    printf("a, b? ");
    scanf("%d %d", &a, &b);
    int perimeter = 2 * (a + b);
    int area = a * b;
    printf("perimeter = %d\n", perimeter);
    printf("area = %d\n", area);
    return 0;
}