#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x, y, temp = 0;
    printf("x y? ");
    scanf("%d %d", &x, &y);
    temp = y;
    y = x;
    x = temp;
    printf("%d %d\n", x, y);

    return 0;
}