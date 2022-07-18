#include <stdio.h>
int main(int argc, const char * argv[]) {
    int x = 0;
    printf("x? ");
    scanf("%d", &x);
    if (x != 0 && x % 2 == 0) {
        printf("2の倍数です\n");
    } else {
        printf("2の倍数ではありません\n");
    }
    if (x != 0 && x % 3 == 0) {
        printf("3の倍数です\n");
    } else {
        printf("3の倍数ではありません\n");
    }
    return 0;
}