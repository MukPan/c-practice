#include <stdio.h>
int main(int argc, const char * argv[]) {
    char inputText[21] = {'\0'};
    int isPalindrome = 1;
    int max = 0;
    printf("input(20文字以下): ");
    scanf("%s", inputText);

    while(inputText[max] != '\0') {
        max++;
    }

    for (int i = 0; i < max; i++) {
        if (inputText[i] != inputText[max-1-i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome == 1) {
        printf("回文OK\n");
    } else {
        printf("回文NG\n");
    }

    return 0;
}