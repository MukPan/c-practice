#include <stdio.h>
int main(int argc, const char * argv[]) {
    int heightsCm[5] = {0};
    double heightsMeter[5] = {0};
    
    //入力
    for (int i = 0; i < 5; i++) {
        printf("%d人目の身長(cm)? ", i + 1);
        scanf("%d", &heightsCm[i]);
    }

    //変換
    for (int i = 0; i < 5; i++) {
        heightsMeter[i] = heightsCm[i] / 100.0;
    }
    
    //出力
    printf("--- Convert Meter ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d人目の身長: %f m\n", i + 1, heightsMeter[i]);
    }
    return 0;
}