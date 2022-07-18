#include <stdio.h>
int main(int argc, const char * argv[]) {
    int total, legs = 0;
    double crane, tortoise = 0;
    printf("total? ");
    scanf("%d", &total);
    printf("legs? ");
    scanf("%d", &legs);

    crane = (total * 4.0 - legs) / 2.0;
    tortoise = total - crane;
    if (crane == (int)crane && crane >= 0 && tortoise >= 0) {
        printf("crane = %d, tortoise = %d\n", (int)crane, (int)tortoise);
    } else {
        printf("cannot be combined\n");
    }
    return 0;
}