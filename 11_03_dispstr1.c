#include <stdio.h>
int main(int argc, const char * argv[]) {
    char array[] = "abcde";
    printf("一文字ずつ印字: ");
    for (int i = 0; i < sizeof(array); i++) {
        printf("%c", array[i]);
    }
    putchar('\n');
    return 0;
}