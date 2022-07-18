#include <stdio.h>
int main(int argc, const char * argv[]) {
    printf("a? ");
    int a = 0;
    scanf("%d", &a);
    if (a > 0) {
        printf("aは正の値です\n");
    }
    return 0;
}