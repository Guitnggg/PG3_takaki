#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// サイコロを振る関数
int RollDice(void) {
    return rand() % 6 + 1; // 1から6のランダムな数を生成
}

// 結果を表示するコールバック関数
void ShowResult(int diceResult, char userGuess) {
    printf("サイコロの出目は %d です。\n", diceResult);

    if (diceResult % 2 == 0) {
        printf("\n出目は丁（偶数）です。\n");
        if (userGuess == 'D' || userGuess == 'd') {
            printf("\nおめでとう！正解です。\n");
        }
        else {
            printf("\n残念！不正解です。\n");
        }
    }
    else {
        printf("\n出目は半（奇数）です。\n");
        if (userGuess == 'H' || userGuess == 'h') {
            printf("\nおめでとう！正解です。\n");
        }
        else {
            printf("\n残念！不正解です。\n");
        }
    }
}

int main(void) {
    // 乱数の初期化
    srand((unsigned int)time(NULL));

    int diceResult; // サイコロの結果
    char userGuess; // ユーザーの予想

    printf("サイコロを振ります。出目が半（奇数）か丁（偶数）かを当ててください。\n");
    printf("半（奇数）の場合は 'H'、丁（偶数）の場合は 'D' を入力してください: ");

    // ユーザーの入力を受け取る
    scanf_s(" %c", &userGuess);

    // サイコロを振る
    diceResult = RollDice();

    // もったいつけるために3秒間待つ
    printf("\n結果を待っています...\n");
   

    // 結果を表示するコールバック関数を呼び出す
    void (*resultCallback)(int, char) = ShowResult; // 関数ポインタ
    resultCallback(diceResult, userGuess); // コールバック関数を呼び出す

    return 0;
}
