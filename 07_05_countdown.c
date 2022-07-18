#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    for (int i = n; 0 < i; i--) {
        printf("%d\n", i);
    }
    return 0;
}