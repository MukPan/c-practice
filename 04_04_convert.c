#include <stdio.h>
int main(int argc, const char * argv[]) {
    int nx, ny, a = 0;
    double dx, dy, b, c = 0;
    printf("nx ny? ");
    scanf("%d %d", &nx, &ny);
    dx = nx;
    dy = ny;
    a = nx / ny;
    b = dx / ny;
    c = nx / dy;
    printf("nx/ny = %d\n", a);
    printf("dx/ny = %f\n", b);
    printf("nx/dy = %f\n", c);
    return 0;
}