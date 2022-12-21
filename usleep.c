#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
int main(int argc, const char * argv[]) {
    for (int i = 0; i < 100; i++) {
        usleep(0.50 * 1000000);
        printf("%d\n", i);
    }
    return 0;
}