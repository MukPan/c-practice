#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    double sum = 0;
    int height = 0;
    double ave = 0;
    printf("人数? ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d人目の身長は? ", i);
        scanf("%d", &height);
        sum += height;
    }
    ave = sum / n;
    printf("平均身長: %f\n", ave);
    return 0;
}