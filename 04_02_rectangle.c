#include <stdio.h>
int main(int argc, char * argv[]) {
    double width = 0;
    double height = 0;
    printf("width? ");
    scanf("%lf", &width);
    printf("height? ");
    scanf("%lf", &height);
    double area = width * height;
    printf("area = %f\n", area);
    return 0;
}