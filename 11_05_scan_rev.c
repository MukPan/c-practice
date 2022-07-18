#include <stdio.h>
int main(int argc, const char * argv[]) {
    char inputText[6] = {'\0'};
    printf("input: ");
    scanf("%s", inputText);
    for(int i = 4; i >= 0; i--) {
        putchar(inputText[i]);
    }
    putchar('\n');
    return 0;
}