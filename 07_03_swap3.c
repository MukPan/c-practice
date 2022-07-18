#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x, y, z, temp, stop = 0;
    printf("x y z? ");
    scanf("%d %d %d", &x, &y, &z);
    
    if (x > y && x > z) {
        temp = z;
        z = x;
        x = temp;
    }
    if (y > x && y > z) {
        temp = z;
        z = y;
        y = temp;
    }
    if(x > y) {
        temp = y;
        y = x;
        x = temp;
    }
    printf("%d %d %d\n", x, y, z);
    return 0;
}