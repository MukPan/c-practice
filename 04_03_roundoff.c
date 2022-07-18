#include <stdio.h>
int main(int argc, const char * argv[]) {
    double dx, a = 0;
    int nx, b = 0;
    printf("dx? ");
    scanf("%lf", &dx);
    a = dx / 2;
    printf("dx/2 = %f\n", a);
    nx = dx;
    printf("nx = %d\n", nx);
    b = nx / 2;
    printf("nx/2 = %d\n", b);
    return 0;
}