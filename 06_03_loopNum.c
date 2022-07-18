#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Hello, World!\n");
    }
}