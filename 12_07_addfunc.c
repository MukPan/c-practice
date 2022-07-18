#include <stdio.h>
//関数のプロトタイプを宣言
int addOf(int a, int b);

//main関数
int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    printf("a b? ");
    scanf("%d %d", &a, &b);
    printf("和は %d\n", addOf(a, b));
    return 0;
}

//関数
int addOf(int a, int b) {
    return (a + b);
}