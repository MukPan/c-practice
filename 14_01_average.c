#include <stdio.h>
int main(int argc, const char * argv[]) {
    int h1 = 0;
    int h2 = 0;
    int h3 = 0;
    double average = 0;
    printf("1人目の身長は? ");
    scanf("%d", &h1);
    printf("2人目の身長は? ");
    scanf("%d", &h2);
    printf("3人目の身長は? ");
    scanf("%d", &h3);
    average = (h1 + h2 + h3) / 3.0;
    printf("平均身長は %f\n", average);
    return 0;
}