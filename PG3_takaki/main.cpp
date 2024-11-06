#include <stdio.h>

// クラステンプレート
template <typename T1, typename T2>
class MinClass {
public:
    // 引数のうち小さい方を返す
    auto Min(T1 a, T2 b) -> decltype(a < b ? a : b) {
        return (a < b) ? a : b;
    }
};

int main() {

    MinClass<int, float> mf1;
    MinClass<int, double> mf2;
    MinClass<float, double> mf3;
    MinClass<float, int> mf4;
    MinClass<double, int> mf5;
    MinClass<double, float> mf6;

    // 結果を出力
    printf("Min(3, 4.5f): %.2f\n", static_cast<double>(mf1.Min(3, 4.5f)));
    printf("Min(5, 7.8): %.2f\n", mf2.Min(5, 7.8));
    printf("Min(9.2f, 10.1): %.2f\n", mf3.Min(9.2f, 10.1));
    printf("Min(6.7f, 2): %.2f\n", static_cast<float>(mf4.Min(6.7f, 2)));
    printf("Min(11.4, 3): %.2f\n", mf5.Min(11.4, 3));
    printf("Min(2.2, 1.9f): %.2f\n", mf6.Min(2.2, 1.9f));

    return 0;
}
