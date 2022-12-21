#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n = 0;
    int sum = 0;
    int count = 0;
    printf("n? ");
    scanf("%d", &n);
    count = n;
    while (count > 0) {
        sum += count;
        count -= 1;
    }
    printf("1から%dまでの和は %d\n", n, sum);
    return 0;
}