#include <stdio.h>
int main(int argc, const char * argv[]) {
    int ij = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ij = i * j;
            printf("%d x %d = %d\n", i, j, ij);
        }
    }
    return 0;
}