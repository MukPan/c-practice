#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    int count = 0;
    printf("n? ");
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        if(n % i == 0) {
            count += 1;
        }
    }
    if (count >= 1 || n == 1 || n == 0) {
        printf("素数ではありません\n");
    } else {
        printf("素数です\n");
    }
    return 0;
}