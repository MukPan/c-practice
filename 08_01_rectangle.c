#include <stdio.h>
int main(int argc, const char * argv[]) {
    int h, w = 0;
    printf("h w? ");
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}