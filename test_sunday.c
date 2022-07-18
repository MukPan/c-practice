#include <stdio.h>
#include <time.h>
#include <unistd.h>
//関数のプロトタイプを宣言
void printClock(int size, int color, int hour, int min, int sec);

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
・PM/AMを追加する(scanf)
・size2以上のとき、月/日/曜日を追加する(scanf)
・size2以上のとき、秒数を小さくするorなくす(scanf)
・最初に設定項目を追加する(scanf)
・終了方法をかんがえておく
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
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);

    //size設定
    printf("サイズ(倍数)を自然数で入力してください(10倍まで): ");
    scanf("%d", &size);
    printf("size * %d\n",size);
    if (!(size > 1 || size < 10)) return 0; //実行不可処理 errorMessage()?
    

    //color設定
    printf("サイズを入力してください\n");
    printf("0:白, 1:赤, 2:緑, 3:黄, 4:紫, 5:ピンク, 6:水色\n");
    printf(": ");
    scanf("%d", &color);
    if (color == 0) {
        color = 7;  //\033[37m (37は白)
    }
    

    //本体
    //sleepをscanf(gamingcolor fast slow)で得た値で、0.2とか0.25とかにする→ゲーミング
    while (1) {
        sleep(1);
        printf("\033[2K");//行全体削除
        time_t t = time(NULL);
        localtime_r(&t, &tm);
        printClock(size, color, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\033[%dF", 5 * size + 6);//カーソルを5*size行上に移動
        
    }
    return 0;
}



//void printClock(int size, int color, int hour, int min, int sec);
//関数

//error関数

//引数に数字を入力するとでかくなって出力される。
void printClock(int size, int color, int hour, int min, int sec) {
    //時分秒を配列にまとめる {01 : 23 : 45}
    //[10]コロン, [11]空白
    int HMSdata[15] = {hour/10, 11, hour%10, 11, 10, 11, min/10, 11, min%10, 11, 10, 11, sec/10, 11, sec%10};
    //曜日を配列にまとめる {S U N}
    //sun={10,12,7}
    //[14]空白
    int Wdata[5] = {10, 14, 12, 14, 7};

    //数字と記号
    //1:■, 0:空白, -1:詰める
    int bigNumberList[12][5][5] = {
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
        //:コロン(10)
        {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        },
        //空白(11)
        {
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        }
    };

    //アルファベット
    int bigAlphabetList[15][5][5] = {
        //[0]A
        {
        {0, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 1, -1},
        {1, 0, 0, 1, -1},
        },
        //[1]D
        {
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        },
        //[2]E
        {
        {1, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 1, -1},
        },
        //[3]F
        {
        {1, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 0, -1},
        {1, 0, 0, 0, -1},
        },
        //[4]H
        {
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        },
        //[5]I
        {
        {1, 1, 1, -1, -1},
        {0, 1, 0, -1, -1},
        {0, 1, 0, -1, -1},
        {0, 1, 0, -1, -1},
        {1, 1, 1, -1, -1},
        },
        //[6]M
        {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        },
        //[7]N
        {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        },
        //[8]O
        {
        {0, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {0, 1, 1, 0, -1},
        },
        //[9]R
        {
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        {1, 0, 0, 1, -1},
        },
        //[10]S
        {
        {0, 1, 1, 1, -1},
        {1, 0, 0, 0, -1},
        {0, 1, 1, 0, -1},
        {0, 0, 0, 1, -1},
        {1, 1, 1, 0, -1},
        },
        //[11]T
        {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        },
        //[12]U
        {
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {1, 0, 0, 1, -1},
        {0, 1, 1, 0, -1},
        },
        //[13]W
        {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        },
        //[14]空白
        {
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        {-1, -1, 0, -1, -1},
        },
    };

    //出力[size(時分秒)]
    for (int i = 0; i < 5; i++) {
        //size(縦幅5*size)
        for (int j = 0; j < size; j++) {
            //全文字分の行を構成 HMSdata[0-15]
            for (int k = 0; k < 15; k++) {
                //１文字分の行を構成
                for (int l = 0; l < 5; l++) {
                    //size(横幅5*size)
                    for (int m = 0; m < size; m++) {
                        if (bigNumberList[HMSdata[k]][i][l] == 1) {
                            printf("■\033[3%dm", color);
                        } else if (bigNumberList[HMSdata[k]][i][l] == 0) {
                            putchar(' ');
                        }
                    }
                }
            }
            putchar('\n');
        }
    }
    putchar('\n');//1行空ける

    //出力[曜日]
    for (int i = 0; i < 5; i++) {
        //全文字分の行を構成 Wdata[0-5]
        for (int j = 0; j < 5; j++) {
            //1文字分の行を構成
            for (int k = 0; k < 5; k++) {
                if (bigAlphabetList[Wdata[j]][i][k] == 1) {
                    printf("■\033[3%dm", color);
                } else if (bigAlphabetList[Wdata[j]][i][k] == 0) {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
}

