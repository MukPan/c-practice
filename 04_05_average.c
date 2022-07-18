#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a, b, c = 0;
    double average = 0;
    printf("No.1? ");
    scanf("%d", &a);
    printf("No.2? ");
    scanf("%d", &b);
    printf("No.3? ");
    scanf("%d", &c);
    average = (a + b + c) / 3.0;
    printf("average = %f\n", average);
    return 0;
}