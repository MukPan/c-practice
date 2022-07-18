#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned int i, j;

    for (i = 1; i <= 10; i++) {
        (void) sleep(1);//実行開始するまでの時間

        printf("\033[2K");//その行を削除
        putchar('[');
        for (j = 0; j < i; j++) {
            putchar('#');//iの数だけ#を入力
        }
        for (; j < 10; j++) {
            putchar(' ');
        }
        putchar(']');
        putchar('\n');
//           その行を削除//カーソルを行頭に移動
        printf("\033[2K\033[G %d sec\n", i);
        printf("\033[2F");//カーソルを2個上に移動
        fflush(stdout); // バッファを強制的に出力.//なくてもうごく？
    }

    puts(""); // 改行表示.

    return 0;
}

//一つずつ増やしているわけではなく、全部消してもう一度書き直している。