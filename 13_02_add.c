#include <stdio.h>
//関数のプロトタイプを宣言
void addOf(int, int);

//main関数
int main(int argc, const char* argv[]) {
    // 宣言, 変数は必ず初期化を行う
    int a = 5, b = 10;
    //  関数の実行 & 出力
    addOf(a, b);
    return 0;
}

//関数
void addOf(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}