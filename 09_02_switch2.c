#include <stdio.h>
int main(int argc, const char * argv[]) {
    char ch;
    printf("text? ");
    //一文字受け取りchに代入
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case ' ':
            putchar('\n');
            break;
            default:
            putchar(ch);
            break;
        }
    }
    putchar('\n');
    return 0;
}