int main() {
    int inputMin = 0;
    int compareMin = 0;
    int boardingT = 8;
    int boardingM = 4;//8:04→404
    zikokuhyo[4][2] = {
        {8, 0},//400分
        {8, 5},//405分
        {8, 10},
        {8, 15},//個数４個
    };
    //入力された時刻を分単位に直す
    inputMin = 60 * boardingT + boardingM;
    for (int i = 0; i < 4; i++) {
        //比較する時刻を分単位に直す
        compareMin = 60 * zikokuhyo[i][0] + zikokuhyo[i][1];
        if (inputMin <= compareMin) {
            printf("%d %d", zikokuhyo[i][0],zikokuhyo[i][1]);
            break;
        }
    }

}