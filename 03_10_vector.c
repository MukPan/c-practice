#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x, y;
    printf("(x, y)? ");
    scanf("(%d, %d)", &x, &y);
    printf("(%d, %d) -> (%d, %d)\n", x, y, 2*x, 2*y);
    return 0;
}