#include <stdio.h>
int main(int argc, const char * argv[]) {
    char searchTerm[] = {'\0'};
    int index = 0; //配列番号
    int end = 0;
    char paragraph[] =
    "we hold these truths to be self-evident, that all men are created "
    "equal, that they are endowed by their creator with certain unalienable "
    "rights, that among these are life, liberty and the pursuit of "
    "happiness.";

    printf("searchTerm: ");
    scanf("%s", searchTerm);
    
    while (paragraph[index] != '.') {
        //空白処理
        if(paragraph[index] == ' ' || index == 0) {
            if(paragraph[index] == ' ') {
                index++;
            }
            //判定
            for (int i = 0; i < 20; i++) {
                if(searchTerm[i] == '\0') { //完了！
                    end = 1;
                    break;
                }
                if(searchTerm[i]!= paragraph[index+i]) { //不連続
                    break;
                }
            }
        }
        if (end == 1) {
            break;
        }
        index++;
    }
    if (end == 0) {
        index = -1;
    }
    printf("indexOf: %d\n", index);
    return 0;
}