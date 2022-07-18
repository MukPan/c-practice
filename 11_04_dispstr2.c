#include <stdio.h>
int main(int argc, const char * argv[]) {
    char inputText[11] = {'\0'};
    printf("入力(10文字以内): ");
    scanf("%s", inputText);
    for (int i = 0; i < sizeof(inputText); i++) {
        printf("%c", inputText[i]);
    }
    putchar('\n');
    return 0;
}