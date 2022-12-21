#include <stdio.h>
int f(int x);
int main(int argc, const char * argv[]) {
    printf("f(0)=%d\n", f(0));
    printf("f(1)=%d\n", f(1));
    printf("f(2)=%d\n", f(2));
    printf("f(3)=%d\n", f(3));
    printf("f(4)=%d\n", f(4));
    return 0;
}

int f(int x) {
    return 2 * x + 1;
}