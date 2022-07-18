#include <stdio.h>
#include <time.h>
#include <unistd.h>

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
        printf("%d\n",tm.tm_sec);
    }
}