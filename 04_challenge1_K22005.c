#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x, a, b, c, reverse = 0;
    printf("x? ");
    scanf("%d", &x);
    //abc
    a = x / 100;
    b = x % 100 / 10;
    c = x % 100 % 10;
    //cba
    printf("reverse x = %d%d%d\n", c, b, a);
    return 0;
}