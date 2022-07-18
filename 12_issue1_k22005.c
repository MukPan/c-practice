#include <stdio.h>
//関数のプロトタイプを宣言
long factOf(int n);

//main関数
int main(int argc, const char * argv[]) {
    int n = 0;
    printf("n? ");
    scanf("%d", &n);
    printf("%dの階乗は %ld\n", n, factOf(n));
    return 0;
}

//関数
long factOf(int n) {
    long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return (ans);
}