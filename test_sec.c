#include <stdio.h>
#include <time.h>
#include <unistd.h>
//関数のプロトタイプを宣言
void printNumber(int sec);


//main関数
int main(int argc, const char * argv[]) {
    int true = 1;
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);
    while (true == 1) {
        for (int i = 0; i < 60; i++) {
            sleep(1);
            printf("\033[2K");//行全体削除
            printNumber((tm.tm_sec + i) % 60);
            printf("\033[5F");//カーソルを5行上に移動
        }
    }
    return 0;
}




//関数




//引数に数字を入力するとでかくなって出力される。(完成)
//ex//printNumber(2);
void printNumber(int sec) {
    
    int BigNumberList[10][5][5] = {
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
    };
    //59
    ////出力////
    for (int i = 0; i < 5; i++) {
        //[0] 0
        for (int j = 0; j < 5; j++) {
            if(BigNumberList[sec / 10][i][j] == 1) {
                printf("■");
            } else {
                putchar(' ');
            }
        }
        //0[ ]0
        putchar(' ');
        //0 [0]
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
