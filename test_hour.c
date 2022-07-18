#include <stdio.h>
#include <time.h>
#include <unistd.h>
//関数のプロトタイプを宣言
void printNumber(int hour, int min, int sec);


//main関数
int main(int argc, const char * argv[]) {
    int true = 1;
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);
    //誤差を修正
    tm.tm_sec += 2;
    while (true == 1) {
        for (int i = tm.tm_hour; i < 24; i++) {
            for (int j = tm.tm_min; j < 60; j++) {
                for (int k = tm.tm_sec; k < 60; k++) {
                    usleep(999000);// /1000000μsで1s //遅延はここで修正！！
                    printf("\033[2K");//行全体削除
                    printNumber(i, j, k);
                    //(min, sec)
                    printf("\033[5F");//カーソルを5行上に移動
                }
                tm.tm_sec = 0;
            }
            tm.tm_min = 0;
        }
        tm.tm_hour = 0;
    }
    return 0;
}




//関数




//引数に数字を入力するとでかくなって出力される。(完成)
//ex//printNumber(2);
void printNumber(int hour, int min, int sec) {
    
    int BigNumberList[11][5][5] = {
        //0
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //1
        {
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //2
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        },
        //3
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //4
        {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //5
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //6
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //7
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //8
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //9
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //:
        {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        }
    };
    //data[3] = {hour, min, sec};
    ////0 0 : 0 0 : 0 0
    ////出力////
    for (int i = 0; i < 5; i++) {
        //[0] 0 : 0 0 : 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[hour / 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0[ ]0 : 0 0 : 0 0
        putchar(' ');
        //0 [0] : 0 0 : 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[hour % 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0[ ]: 0 0 : 0 0
        putchar(' ');
        //0 0 [:] 0 0 : 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0 :[ ]0 0 : 0 0
        putchar(' ');
        //0 0 : [0] 0 : 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[min / 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0 : 0[ ]0 : 0 0
        putchar(' ');
        //0 0 : 0 [0] : 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[min % 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0 : 0 0[ ]: 0 0
        putchar(' ');
        //0 0 : 0 0 [:] 0 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0 : 0 0 :[ ]0 0
        putchar(' ');
        //0 0 : 0 0 : [0] 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[sec / 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0 0 : 0 0 : 0[ ]0
        putchar(' ');
        //0 0 : 0 0 : 0 [0]
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[sec % 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //改行
        putchar('\n');
    }
}
