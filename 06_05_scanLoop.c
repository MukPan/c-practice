#include <stdio.h>
int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 5; i++) {
        int a = 0;
        printf("a? ");
        scanf("%d", &a);
        printf("%d: %d\n", i, a);
    }
    return 0;
}