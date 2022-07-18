#include <stdio.h>
//関数のプロトタイプを宣言
void printFunc(void);

//main関数
int main(int argc, const char* argv[]) {
    printFunc();
    return 0;
}

//関数
void printFunc(void) {
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }
}