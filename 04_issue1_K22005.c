#include <stdio.h>
int main(int argc, const char * argv[]) {
    int height, weight;
    double heightM, standardWeight, bmi;
    printf("height? ");
    scanf("%d", &height);
    printf("weight? ");
    scanf("%d", &weight);
    heightM = height / 100.0;
    standardWeight = (height - 100) * 0.9;
    bmi = weight / (heightM * heightM);
    printf("standardWeight = %f\n", standardWeight);
    printf("BMI = %f\n", bmi);
    return 0;
}