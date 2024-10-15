#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

// コールバック関数
typedef void (*PFunc)(bool);

void Result(bool isCorrect) {
    if (isCorrect) {
        printf("\nおめでとう大正解！\n");
    }
    else {
        printf("\n残念、不正解\n");
    }
}

// 奇数か偶数かを判定
bool IsEven(int number) {
    return number % 2 == 0;
}

// サイコロを振る関数
int RollDice() {
    return rand() % 6 + 1;
}

void GuessOddOrEven(PFunc callback) {
    int dice = RollDice();
    int Guess;
    bool isEven = IsEven(dice);

    printf("丁（偶数）か半（奇数）か(偶数: 2, 奇数: 1): ");
    scanf_s("%d", &Guess);

    bool userIsEven = (Guess == 2);

    printf("正解は...\n");
    Sleep(3000);  // 3秒待つ

    //結果を表示
    callback(isEven == userIsEven);
}

int main() {
    srand(time(NULL));

    GuessOddOrEven(Result);

    return 0;
}