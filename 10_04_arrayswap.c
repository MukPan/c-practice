#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    int x = 0;
    int y = 0;
    int temp = 0;
    printf("何番目を入れ替えますか? ");
    scanf("%d %d", &x, &y);
    temp = a[x - 1];
    a[x - 1] = a[y - 1];
    a[y - 1] = temp;
    for (int i = 0; i < 5; i++) {
        printf("a[%d]=%d\n", i, a[i]);
    }
    return 0;
}