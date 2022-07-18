#include <stdio.h>
//関数のプロトタイプを宣言
int maxOf(int a, int b);

//main関数
int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    int max = 0;
    printf("a b? ");
    scanf("%d %d", &a, &b);
    max = maxOf(a, b);
    printf("大きい方の値は %d\n", max);
    return 0;
}

//関数
int maxOf(int a, int b) {
    if (a > b) {
        return (a);
    } else {
        return (b);
    }
}