#include <stdio.h>

// 再帰的な賃金を計算する関数
int RecursiveWage(int hour) {
    if (hour == 1) {
        return 1172; // 1時間目の時給は100円アップした1172円
    }
    return (RecursiveWage(hour - 1) * 2 - 50); // 前の時給*2 - 50円
}

int main() {
    const int normalWage = 1072; // 一般的な時給
    int hours; // 働く時間数
    int totalNormalWage = 0; // 一般的な賃金体系での総収入
    int totalRecursiveWage = 0; // 再帰的な賃金体系での総収入

    // 働く時間数の入力を求める
    printf("何時間働くかを入力してください: ");
    scanf_s("%d", &hours);

    // 賃金体系の比較
    printf("\n時給の比較:\n");
    printf("時間 | 一般的な賃金体系 | 再帰的な賃金体系\n");
    printf("--------------------------------------\n");

    for (int i = 1; i <= hours; i++) {
        int normalHourlyWage = normalWage;
        int recursiveHourlyWage = RecursiveWage(i);

        // 総収入を計算
        totalNormalWage += normalHourlyWage;
        totalRecursiveWage += recursiveHourlyWage;

        // 時給の比較を表示
        printf("%3d  | %12d 円    | %12d 円\n", i, normalHourlyWage, recursiveHourlyWage);
    }

    // 最終的な総収入の比較を表示
    printf("\n%d時間働いた場合の総収入:\n", hours);
    printf("一般的な賃金体系の総収入: %d 円\n", totalNormalWage);
    printf("再帰的な賃金体系の総収入: %d 円\n", totalRecursiveWage);

    // どちらが有利かを判断
    if (totalRecursiveWage > totalNormalWage) {
        printf("\n再帰的な賃金体系が有利です。\n");
    }
    else if (totalRecursiveWage < totalNormalWage) {
        printf("\n一般的な賃金体系が有利です。\n");
    }
    else {
        printf("\nどちらの賃金体系も同じです。\n");
    }

    return 0;
}
