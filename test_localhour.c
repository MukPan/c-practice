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

    while (true == 1) {
        sleep(1);
        printf("\033[2K");//行全体削除
        time_t t = time(NULL);
        localtime_r(&t, &tm);
        printNumber(tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\033[5F");//カーソルを5行上に移動
        
    }
    return 0;
}




//関数

//引数に数字を入力するとでかくなって出力される。
void printNumber(int hour, int min, int sec) {
    int data[3] = {hour, min, sec};
    int bigNumberList[11][5][5] = {
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
        //:(10)
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
        for (int j = 0; j < 3; j++) {
            //[0] 0 : 
            for (int k = 0; k < 5; k++) {
                if(bigNumberList[data[j] / 10][i][k] == 1) {
                    printf("■");
                } else {
                    putchar(' ');
                }
            }
            //0[ ]0 :
            putchar(' ');
            //0 [0] : 
            for (int k = 0; k < 5; k++) {
                if(bigNumberList[data[j] % 10][i][k] == 1) {
                    printf("■");
                } else {
                    putchar(' ');
                }
            }

            if (j == 2) break;

            //0 0[ ]: 
            putchar(' ');
            //0 0 [:] 
            for (int k = 0; k < 5; k++) {
                if(bigNumberList[10][i][k] == 1) {
                    printf("■");
                } else {
                    putchar(' ');
                }
            }
            //0 0 :[ ]
            putchar(' ');
        }
        putchar('\n');
    }
}

//small(時分秒) or big(曜日時分(秒))
/*
■■■■
■■■
■■■
■■■
■
■
■
■
■
■
■
*/