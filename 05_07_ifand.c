#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a, b = 0;
    printf("a? ");
    scanf("%d", &a);
    printf("b? ");
    scanf("%d", &b);
    if (a > 0 && b > 0) {
        printf("aとbは正です\n");
    } else {
        printf("aとbのどちらかは負もしくは0です\n");
    }
    return 0;
}