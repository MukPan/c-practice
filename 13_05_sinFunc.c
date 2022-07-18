#include <stdio.h>
#include <math.h>
//関数のプロトタイプを宣言
double deg2Rad(double);

//main関数
int main(int argc, const char * argv[]) {
    double theta = 0;
    double rad = 0;
    printf("input: ");
    scanf("%lf", &theta);
    rad = deg2Rad(theta);
    printf("sin (%f) = %f\n", theta, sin(rad));
    return 0;
}

//関数
double deg2Rad(double th) {
    return th * M_PI / 180.0;
}