#include <stdio.h>
#include <time.h>
//関数

//引数なし

//main関数
int main(int argc, const char * argv[]) {
    const char *days[] = {"日","月","火","水","木","金","土"};
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);

    printf("%04d年%02d月%02d日(%s)%02d時%02d分%02d秒\n",
        tm.tm_year + 1900,//年
        tm.tm_mon + 1,//月
        tm.tm_mday,//日
        days[tm.tm_wday],//水曜日?
        tm.tm_hour,//時
        tm.tm_min,//分
        tm.tm_sec //秒
        );
    return 0;
}


