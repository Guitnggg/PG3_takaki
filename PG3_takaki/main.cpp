#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

// コールバック関数
void DispResult(int* _, int* kye) {
    int dice = rand() % 2; // 0 or 1 を生成

    if (dice == *kye) {
        if (dice == 0)
            printf("%d で丁(偶数)でした。当たり\n", dice);
        else
            printf("%d で半(奇数)でした。当たり\n", dice);
    }
    else {
        if (dice == 1)
            printf("%d で半(奇数)でした。はずれ\n", dice);
        else
            printf("%d で丁(偶数)でした。はずれ\n", dice);
    }
}

// タイマー関数
void setTimeout(std::function<void(int*, int*)> p, int seconds, int kye) {
    // カウントダウン
    for (int i = seconds; i > 0; i--) {
        Sleep(1000);
        printf("%d...\n", i);
    }

    // コールバック呼び出し
    p(nullptr, &kye);
}

int main() {
    int kye;

    srand(static_cast<unsigned int>(time(NULL))); // ランダム初期化
    printf("丁(偶数)なら 0、半(奇数)なら 1 を打つ\n");
    scanf_s("%d", &kye);

    if (kye == 0) {
        puts("あなたは丁(偶数)を選びました");
    }
    else {
        puts("あなたは半(奇数)を選びました");
    }

    // コールバック関数をセット
    std::function<void(int*, int*)> p = [](int* s, int* kye) {
        DispResult(s, kye);
        };
    setTimeout(p, 3, kye);

    return 0;
}
