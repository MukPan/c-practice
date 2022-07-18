#include <stdio.h>
int main(int argc, const char * argv[]) {
    char ch;
    int answer = 0;
    int isMinus = 0;
    int inputNumber = 0;
    printf("equation? ");
    while ((ch = getchar()) != '=') {
        switch(ch) {
            case '-':
            isMinus = 1;
            break;

            case '+':
            isMinus = 0;
            break;

            case ' ':
            switch(isMinus) {
                case 1:
                answer -= inputNumber;
                break;
                default:
                answer += inputNumber;
                break;
            }
            inputNumber = 0;
            break;

            default:
            inputNumber = (int)ch - 48;
            break;
        }
    }
    printf("answer: %d\n", answer);
    return 0;
}