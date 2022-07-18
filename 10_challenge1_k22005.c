#include <stdio.h>
int main(int argc, const char * argv[]) {
    int primeNumbers[99] = {0};
    int count = 0;
    int flag = 1;
    //1:素数 0:素数じゃない

    //計算
    for (int i = 2; i <= 100; i++) {

        for (int j = 0; j < count; j++) {
            if(i % primeNumbers[j] == 0) {
                //割り切れたら素数flagを0にする。
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            primeNumbers[count] = i;
            count += 1;
        }
        flag = 1;
    }
    
    //出力
    for (int i = 0; i < count; i++) {
        printf("%d, ", primeNumbers[i]);
    }
    putchar('\n');
    return 0;
}