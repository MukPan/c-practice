#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    double theta = 0;
    double rad = 0;
    printf("input: ");
    scanf("%lf", &theta);
    rad = theta * M_PI / 180.0;
    printf("sin (%f) = %f\n", theta, sin(rad));
    return 0;
}
