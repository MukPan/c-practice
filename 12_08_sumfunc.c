#include <stdio.h>
//関数のプロトタイプを宣言
int sumOf(int n);

//main関数
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    printf("1から%dまでの和は %d\n", n, sumOf(n));
    return 0;
}

//関数
int sumOf(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return (sum);
}