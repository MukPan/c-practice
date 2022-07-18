#include <stdio.h>
#include <time.h>
#include <unistd.h>
//関数のプロトタイプを宣言
void printNumber(int size, int hour, int min, int sec);


//main関数
int main(int argc, const char * argv[]) {
    int size = 1;
    int count = 0;
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);

    //size設定
    printf("サイズを自然数で入力してください(小数点以下切り捨て): ");
    scanf("%d", &size);
    printf("size * %d\n",size);
    if (size < 1) return 0;

    //本体
    while (1) {
        sleep(1);
        printf("\033[2K");//行全体削除
        time_t t = time(NULL);
        localtime_r(&t, &tm);
        printNumber(size, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\033[%dF", 5 * size);//カーソルを5*size行上に移動
        
    }
    return 0;
}




//関数

//引数に数字を入力するとでかくなって出力される。
void printNumber(int size, int hour, int min, int sec) {
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
        //行開始
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < 3; k++) {
                //[0] 0 : 
                for (int l = 0; l < 5; l++) {
                    for (int m = 0; m < size; m++) {
                        if(bigNumberList[data[k] / 10][i][l] == 1) {
                            printf("■");
                        } else {
                            putchar(' ');
                        }
                    }
                }
                //0[ ]0 :
                putchar(' ');
                //0 [0] : 
                for (int l = 0; l < 5; l++) {
                    for (int m = 0; m < size; m++) {
                        if(bigNumberList[data[k] % 10][i][l] == 1) {
                            printf("■");
                        } else {
                            putchar(' ');
                        }
                    }
                }

                if (k == 2) break;

                //0 0[ ]: 
                putchar(' ');
                //0 0 [:] 
                for (int l = 0; l < 5; l++) {
                    for (int m = 0; m < size; m++) {
                        if(bigNumberList[10][i][l] == 1) {
                            printf("■");
                        } else {
                            putchar(' ');
                        }
                    }
                }
                //0 0 :[ ]
                putchar(' ');
            }
        putchar('\n');
        }
    }
}

//small(時分秒) or big(曜日時分(秒))
