#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    for (int i = n; i < n + 3; i++) {
        for (int j = 1; j <= 9; j++) {
            int ij = i * j;
            printf("%d x %d = %d\n", i, j, ij);
        }
    }
    return 0;
}