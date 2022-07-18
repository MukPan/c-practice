#include <stdio.h>
#include <math.h>
//関数のプロトタイプを宣言
double calcArea (double);
double calcCircumference (double);
//main関数
int main(int argc, const char * argv[]) {
    double r = 0;
    printf("input r: ");
    scanf("%lf", &r);
    printf("%f %f\n", calcArea(r), calcCircumference(r));
    return 0;
}

/*関数*/

//面積
double calcArea (double r) {
    return r * r * M_PI;
}
//周長
double calcCircumference (double r) {
    return 2 * r * M_PI;
}