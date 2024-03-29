#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
//関数のプロトタイプを宣言
void printClock(int size, int color, int isAMPM, int isSec, int isDetail, int year, int month, int day, int week, int hour, int min, int sec);
void *func(void *arg);
int errorCheck(int value, int min, int max);
//グローバル変数
int flag = 1; 
int beforeSec = -1;
/*注意点
・sizeを大きくしすぎると画面が乱れる.
・sizeを大きくするなら、実行前にコンソールサイズを小さくすること.
・sizeは自然数をにゅうりょくしてください.
・sizeが1倍のとき、サイズ以外の項目は変更することができません.
・コンソールのウインドウを拡大縮小すると画面が乱れることがあります.その際は再起動をお願いします.
・sizeを大きくしてコンソールサイズを小さくすることをおすすめします
・曜日などはsize変更できません
*/


/*機能の候補！！！
・ゲーミングカラー
?レイアウトを増やす
・[PM/AMを追加する(scanf)]
・[size2以上のとき、月/日/曜日を追加する(scanf)]
・[size2以上のとき、秒数を小さくするorなくす(scanf)]
・[終了方法をかんがえておく]
・[曜日が切り替わる時前の表示が残ってる→曜日の後に空白文字をいれればいけるかも？]
・[秒数表示を無効にする]
・[年月日曜を無効にする]
・[秒数設定を無効化した時、コロンを点滅させる]
・
ex.
    変更したい項目の番号を入力してください.
    実行する場合は0を入力してください. //それ以外の数は終了
    0.実行
    1.サイズの変更:*1
    ２.月/日/曜日の表示：有効
    3.秒数の表示:小  //有効/有効(小)/メトロノーム/無効
    入力: 
//size=1に設定された時、秒数以外の以下の項目をすべて無効に
//size=1のとき他の設定の番号を入力しようとすると、警告文と共にループする

*/
//main関数
int main(int argc, const char * argv[]) {
    int size = 1;
    int color = 0;
    int goUp = 0;
    int renewSpeed = 1.0 * 1000000; //初期設定1秒
    int isAMPM = 0; //0:無効, 1:有効
    int isSec = 0; //0:無効, 1:有効
    int isDetail = 0; //0:無効, 1:有効
    int isColonSwitch = 0; //0:無効, 1:有効
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);

    printf("<<CustomClock>>\n");
    //size設定
    printf("サイズ倍率設定(1-10倍)\n");
    printf(": ");
    scanf("%d", &size);
    if (errorCheck(size, 1, 10)) return 0;

    //color設定
    printf("サイズ設定\n");
    printf("0/白, \033[31m1/赤, \033[32m2/緑, \033[33m3/黄, \033[34m4/紫, \033[35m5/ピンク, \033[36m6/水色\n");
    printf("\033[39m: ");
    scanf("%d", &color);
    if (errorCheck(color, 0, 6)) return 0;
    if (color == 0) {
        color = 9;  //\033[39m (39は白(デフォルト))
    }

    //AMPM設定
    printf("AMPM設定\n");
    printf("0/無効, 1/有効\n");
    printf(": ");
    scanf("%d", &isAMPM);
    if (errorCheck(isAMPM, 0, 1)) return 0;
    

    //秒数表示設定
    printf("sec表示設定\n");
    printf("0/無効, 1/有効\n");
    printf(": ");
    scanf("%d", &isSec);
    if (errorCheck(isSec, 0, 1)) return 0;

    //年月日曜表示設定
    printf("年月日曜表示設定\n");
    printf("0/無効, 1/有効\n");
    printf(": ");
    scanf("%d", &isDetail);
    if (errorCheck(isDetail, 0, 1)) return 0;

    //設定反映
    goUp = size * 5;
    if (size != 1 && isDetail == 1) {
        goUp += 6;//曜日分も底上げ
    }

    if (isSec == 0) {
        renewSpeed = 0.50 * 1000000; //コンマ点滅用(0.5秒)
    }

    printf("enter/returnキーで終了します\n");

    //スレッド作成
    pthread_t th[1];
    pthread_create(&th[0], NULL, func, NULL);
    

    //本体
    while (flag) {
        usleep(renewSpeed);//(0.50s)
        printf("\033[2K");//全体削除
        time_t t = time(NULL);
        localtime_r(&t, &tm);
        printClock(
            size, color, isAMPM, isSec, isDetail,//各種設定
            tm.tm_year+1900, tm.tm_mon+1 ,tm.tm_mday, tm.tm_wday,//年月日曜
            tm.tm_hour, tm.tm_min, tm.tm_sec//時分秒
        );
        printf("\033[%dF", goUp);//カーソルを5*size+6行上に移動
    }
    printf("\033[1F");
    printf("\033[2K");//全体削除
    printf("CustomClockを終了します\n");
    return 0;
}




//関数////////////////////////////////////////////////////////////////////////////////////////


/*errorCheck関数*/
//入力可能範囲と入力された値を与え、問題があるとプログラムを終了する
int errorCheck(int value, int min, int max) {
    if (value >= min && value <= max) {
        return 0;
    } else {
        printf("不正な値が入力されました.\nプログラムを終了します.\n");
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
void printClock(int size, int color, int isAMPM, int isSec, int isDetail, int year, int month, int day, int week, int hour, int min, int sec) {
    //0:無効, 1:AM, 2:PM
    int AMorPM = 0;
    //デフォルトでコロン表示
    int colonSwitch = 10;
    //AMPMdata[AMorPM][0-3]
    int AMPMdata[3][4] = {
        {29, 29, 29, 29},
        {12, 11, 18, 28},
        {21, 11, 18, 28},
        };

    //秒数非表示のとき、コロンを非表示(28)、表示(10)を交互に繰り返し点滅させる
    if (isSec == 0) {
        if (beforeSec == sec) {
            colonSwitch = 28; //消す
        }
        beforeSec = sec;
    }

    //secData[isSec0-1][0-4]
    int secData[2][5] = {{29, 29, 29, 29, 29}, {10, 11, sec/10, 11, sec%10}};

    //AMPMが有効なら実行 //関数化できるならやって int getAMPMhour(int hour);
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

    //１段目,時分秒を配列にまとめる ex.{A M[ ]0 1 : 2 3 : 4 5}
    //[10]コロン, [11]空白, [28]空白文字, [29]詰文字
    int HMSdata[19] = {
        AMPMdata[AMorPM][0], AMPMdata[AMorPM][1], AMPMdata[AMorPM][2] ,AMPMdata[AMorPM][3],//{A M[]}
        hour/10, 11, hour%10, 11, colonSwitch, 11,//{1 2 : }
        min/10, 11, min%10, 11, secData[isSec][0], secData[isSec][1],//{3 4 : }
        secData[isSec][2], secData[isSec][3], secData[isSec][4],//{5 6}
    };
    //secData
    

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

    
    //2段目,年月日曜を配列にまとめる ex.{2 0 2 2 / 0 7 / 1 4 / T H U}
    int YMDWdata[28] = {
        year/1000, 11, year%1000/100, 11, year%100/10, 11, year%10, 11, 27, 11,//{2 0 2 2 / }
        month/10, 11, month%10, 11, 27, 11,//{0 7 / }
        day/10, 11, day%10, 11, 27, 11,//{1 4 / }
        Wdata[week][0], 11, Wdata[week][1], 11, Wdata[week][2], 28//{T H U[ ]}
    };

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
///////////////////////////////////////////
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
        ///////////////////////////
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


    

    //下のforを改行した後2回実行?

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
                            printf("\033[3%dm■", color);
                        } else if (bigList[HMSdata[k]][i][l] == 0) {
                            putchar(' ');
                        }
                    }
                }
            }
            putchar('\n');
        }
    }
    
    

    if (size != 1 && isDetail == 1) {
        putchar('\n');//1行空ける
        //出力[曜日]
        for (int i = 0; i < 5; i++) {
            //全文字分の行を構成 YMDWdata[0-27]
            for (int j = 0; j < 28; j++) {
                //1文字分の行を構成
                for (int k = 0; k < 5; k++) {
                    if (bigList[YMDWdata[j]][i][k] == 1) {
                        printf("\033[3%dm■", color);
                    } else if (bigList[YMDWdata[j]][i][k] == 0) {
                        putchar(' ');
                    }
                }
            }
            putchar('\n');
        }
    }
}

