#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
//////////関数のプロトタイプを宣言//////////
void printClock(int size, int firstColor, int secondColor, int isAMPM, int isSec, int isDetail, int year, int month, int day, int week, int hour, int min, int sec);
void *func(void *arg);
int errorCheck(int value, int min, int max);
//グローバル変数
int flag = 1; 
int beforeSec = -1;


//////////main関数/////////////////////
int main(int argc, const char * argv[]) {
    int size = 1;
    int firstColor = 0;
    int secondColor = 0;
    int goUp = 0;
    int renewSpeed = 1.0 * 1000000; //初期設定1秒
    int isAMPM = 0; //0:無効, 1:有効
    int isSec = 0; //0:無効, 1:有効
    int isDetail = 0; //0:無効, 1:有効
    int isColonSwitch = 0; //0:無効, 1:有効
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);

    //タイトル
    printf("\033[1m<<CustomClock>>\n\033[0m");

    //size設定
    printf("サイズ倍率設定(1-10倍)\n: ");
    scanf("%d", &size);
    if (errorCheck(size, 1, 10)) return 0;

    //年月日曜表示設定(size1のとき無視)
    if (size != 1) {
        printf("年月日曜表示設定\n");
        printf("(1〜3倍推奨)\n");
        printf("0/無効, 1/有効\n: ");
        scanf("%d", &isDetail);
        if (errorCheck(isDetail, 0, 1)) return 0;
    }

    //firstColor設定
    printf("時分秒(1段目)カラー設定\n");
    printf("0/白, \033[31m1/赤, \033[32m2/緑, \033[33m3/黄, \033[34m4/紫, \033[35m5/ピンク, \033[36m6/水色\n\033[39m: ");
    scanf("%d", &firstColor);
    if (errorCheck(firstColor, 0, 6)) return 0;
    if (firstColor == 0) firstColor = 9;  //\033[39m (39は白(デフォルト))

    //secondColor設定(size1のとき無視)
    if (size != 1) {
        printf("年月日曜(2段目)カラー設定\n");
        printf("0/白, \033[31m1/赤, \033[32m2/緑, \033[33m3/黄, \033[34m4/紫, \033[35m5/ピンク, \033[36m6/水色\n\033[39m: ");
        scanf("%d", &secondColor);
        if (errorCheck(secondColor, 0, 6)) return 0;
        if (secondColor == 0) secondColor = 9;  //\033[39m (39は白(デフォルト))
    }

    //AMPM設定
    printf("AMPM表示設定\n");
    printf("0/無効, 1/有効\n: ");
    scanf("%d", &isAMPM);
    if (errorCheck(isAMPM, 0, 1)) return 0;
    
    //秒数表示設定
    printf("秒数表示設定\n");
    printf("0/無効, 1/有効\n: ");
    scanf("%d", &isSec);
    if (errorCheck(isSec, 0, 1)) return 0;

    //一部設定反映
    goUp = size * 5;
    if (size != 1 && isDetail == 1) {
        goUp += 6;//曜日分も底上げ
    }

    if (isSec == 0) {
        renewSpeed /= 2; //コンマ点滅用(0.5秒)
    }

    /////本体/////
    printf("enter/returnキーで終了します.\n");
    //スレッド作成
    pthread_t th[1];
    pthread_create(&th[0], NULL, func, NULL);
    //本体
    while (flag) {
        usleep(renewSpeed);//(0.50s or 1.0s)
        time_t t = time(NULL);
        localtime_r(&t, &tm);
        printClock(
            size, firstColor, secondColor, isAMPM, isSec, isDetail,//各種設定
            tm.tm_year+1900, tm.tm_mon+1 ,tm.tm_mday, tm.tm_wday,//年月日曜
            tm.tm_hour, tm.tm_min, tm.tm_sec//時分秒
        );
        printf("\033[%dF", goUp);//カーソルを5*size+6行上に移動
        printf("\033[2K");//全体削除
    }
    printf("\033[1F");//カーソルを先頭
    printf("\033[2K");//全体削除
    printf("\033[39mCustomClockを終了します.\n");
    printf("\033[1m<<CustomClock>>\n\033[0m");
    return 0;
}


//////////関数/////////////////////////
/*errorCheck関数*/
//入力可能範囲と入力された値を与え、問題があるとプログラムを終了する
int errorCheck(int value, int min, int max) {
    if (value >= min && value <= max) {
        return 0;
    } else {
        printf("不正な値が入力されました.\nプログラムを終了します.\n");
        printf("\033[1m<<CustomClock>>\n\033[0m");
        return 1;
    }
}

/*func関数*/
//flag管理用マルチスレッド、本体起動時にreturnキーを押すと終了する
void *func(void *arg) {
    getchar(); //1度だけだと本体が起動した瞬間終了してしまう
    getchar(); 
    flag = 0;
    return NULL;
}

/*printClock関数*/
//設定内容と現在時刻を与えると時計を表示する
void printClock(int size, int firstColor, int secondColor, int isAMPM, int isSec, int isDetail, int year, int month, int day, int week, int hour, int min, int sec) {
    /////１段目/////
    int AMorPM = 0; //0:無効, 1:AM, 2:PM
    int colonSwitch = 10; //デフォルトでコロン(10)表示
    //AMPMdata[AMorPM0-2][0-3]
    int AMPMdata[3][4] = {
        {29, 29, 29, 29}, //{    }
        {12, 11, 18, 28}, //{A M }
        {21, 11, 18, 28}, //{P M }
        };

    //secData[isSec0-1][0-4]
    int secData[2][5] = {
        {29, 29, 29, 29, 29}, //{}
        {10, 11, sec/10, 11, sec%10}, //{: 5 6} 
    };

    //コロンの点滅処理
    if (isSec == 0) {
        if (beforeSec == sec) {
            colonSwitch = 28; //消す
        }
        beforeSec = sec;
    }

    //AMPM表記に変換
    if (isAMPM == 1) {
        if (hour < 12) {
            AMorPM = 1;
        } else {
            AMorPM = 2;
        }
        if ((hour == 0 || hour == 12) && min == 0 && sec == 0) {
            hour = 12; //00:00:00, 12:00:00 → PM/AM 12:00:00
        } else {
            hour %= 12; //ex. 23:00:00 → PM 11:00:00 //ex. 12:00:01 → PM 00:00:01
        }
    }

    //時分秒を配列にまとめる ex.{A M[]0 1 : 2 3 : 4 5}
    //[10]コロン, [11]空白, [28]空白文字, [29]詰文字
    int HMSdata[19] = {
        AMPMdata[AMorPM][0], AMPMdata[AMorPM][1], AMPMdata[AMorPM][2] ,AMPMdata[AMorPM][3],//{A M[]}
        hour/10, 11, hour%10, 11, colonSwitch, 11,//{1 2 : }
        min/10, 11, min%10, 11, secData[isSec][0], secData[isSec][1],//{3 4 : }
        secData[isSec][2], secData[isSec][3], secData[isSec][4],//{5 6}
    };
    
    
    /////2段目/////
    //Wdata[week日0-土6][5]
    int Wdata[7][3] = {
        {23, 25, 19},//日(SUN)
        {18, 20, 19},//月(MON)
        {24, 25, 14},//火(TUE)
        {26, 14, 13},//水(WED)
        {24, 16, 25},//木(THU)
        {15, 22, 17},//金(FRI)
        {23, 12, 24},//土(SAT)
    };

    //年月日曜を配列にまとめる ex.{2 0 2 2 / 0 7 / 1 4 / T H U}
    int YMDWdata[28] = {
        year/1000, 11, year%1000/100, 11, year%100/10, 11, year%10, 11, 27, 11,//{2 0 2 2 / }
        month/10, 11, month%10, 11, 27, 11,//{0 7 / }
        day/10, 11, day%10, 11, 27, 11,//{1 4 / }
        Wdata[week][0], 11, Wdata[week][1], 11, Wdata[week][2], 28//{T H U[ ]}
    };

    /////デジタル表記/////
    //1:■, 0:空白, -1:詰める
    int bigList[30][5][5] = {
        //[0]0
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[1]1
        {
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //[2]2
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        },
        //[3]3
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[4]4
        {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //[5]5
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[60]6
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[7]7
        {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        },
        //[8]8
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[9]9
        {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        },
        //[10]コロン
        {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        },
        //[11]空白
        {
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        },
        //[12]A
        {
        {0, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 1, -1},
        {1, 0, 0, 1, -1},
        },
        //[13]D
        {
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        },
        //[14]E
        {
        {1, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 1, -1},
        },
        //[15]F
        {
        {1, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 0, -1},
        {1, 0, 0, 0, -1},
        },
        //[16]H
        {
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        },
        //[17]I
        {
        {1, 1, 1, -1, -1},
        {0, 1, 0, -1, -1},
        {0, 1, 0, -1, -1},
        {0, 1, 0, -1, -1},
        {1, 1, 1, -1, -1},
        },
        //[18]M
        {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        },
        //[19]N
        {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        },
        //[20]O
        {
        {0, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {0, 1, 1, 0, -1},
        },
        //[21]P
        {
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 0, -1},
        },
        //[22]R
        {
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        },
        //[23]S
        {
        {0, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {0, 1, 1, 0, -1},
        {0, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        },
        //[24]T
        {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        },
        //[25]U
        {
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {0, 1, 1, 0, -1},
        },
        //[26]W
        {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        },
        //[27]スラッシュ
        {
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        },
        //[28]空白文字 //曜日が切り替わる時、表示が残るのを防ぐ
        {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        },
        //[29]詰文字 //AMPMが無効になっている時、詰める
        {
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        },
    };

/////出力部分/////

    //1段目
    //出力[size(時分秒)]
    for (int i = 0; i < 5; i++) {
        //size(縦幅5*size)
        for (int j = 0; j < size; j++) {
            //全文字分の行を構成 HMSdata[0-18]
            for (int k = 0; k < 19; k++) {
                //１文字分の行を構成
                for (int l = 0; l < 5; l++) {
                    //size(横幅5*size)
                    for (int m = 0; m < size; m++) {
                        if (bigList[HMSdata[k]][i][l] == 1) {
                            printf("\033[3%dm■", firstColor);
                        } else if (bigList[HMSdata[k]][i][l] == 0) {
                            putchar(' ');
                        }
                    }
                }
            }
            putchar('\n');
        }
    }
    //2段目
    if (size != 1 && isDetail == 1) {
        putchar('\n');//1行空ける
        //出力[曜日]
        for (int i = 0; i < 5; i++) {
            //全文字分の行を構成 YMDWdata[0-27]
            for (int j = 0; j < 28; j++) {
                //1文字分の行を構成
                for (int k = 0; k < 5; k++) {
                    if (bigList[YMDWdata[j]][i][k] == 1) {
                        printf("\033[3%dm■", secondColor);
                    } else if (bigList[YMDWdata[j]][i][k] == 0) {
                        putchar(' ');
                    }
                }
            }
            putchar('\n');
        }
    }
}